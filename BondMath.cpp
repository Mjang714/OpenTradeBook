#include<vector>
#include<string>
#include<iostream>
#include<cmath>
#include<stdlib.h>

double compoundedToContRate(double rate, int compounding) {
    return compounding*log(1 + (rate/compounding));
}

double contRateToCompounded(double rate, int compounding) {
    return compounding*(exp(rate/compounding)-1);
}

double fprime(double yield, std::vector<double> maturitySchedule, std::vector<double> cashflowSchedule) {
    double result = 0.0;
    
    for(int i = 0; i < cashflowSchedule.size(); i++) {
        result += cashflowSchedule[i]*maturitySchedule[i]*exp(-yield * maturitySchedule[i]);
    }
    
    return result;
}

double f(double yield, double price, std::vector<double> maturitySchedule, std::vector<double> cashflowSchedule) {
    double result = 0.0;
    
    for(int i = 0; i < cashflowSchedule.size(); i++) {
        result += cashflowSchedule[i]*exp(-yield * maturitySchedule[i]);
    }
    
    result += -price;
 
    return result;
}

// Here we are computing the yield of the bond recursively
double computeYieldHelper(double yield, double price, std::vector<double> maturitySchedule, std::vector<double> cashflowSchedule) {
    double newYield = yield + (f(yield,price,maturitySchedule,cashflowSchedule)/fprime(yield,maturitySchedule,cashflowSchedule));
    
    if(abs(newYield - yield) > 0.00){
        return computeYieldHelper(newYield,price,maturitySchedule,cashflowSchedule);
    }
    
    else{
        return newYield;
    }
}

// Here the bond yield is computed via newton method and returned as the continusous rate
double computeYield(std::vector<double> maturitySchedule, std::vector<double> cashflowSchedule, double bondPrice){

    return computeYieldHelper(0.0,bondPrice,maturitySchedule,cashflowSchedule);
}

std::vector<double> createTimeMaturitySchedule(int paymentFreq, double years) {
    
    int numberOfMaturities = paymentFreq*years;
    
    double unitOfTime = 1.0/paymentFreq;
    
    std::vector<double> maturitySchedule(numberOfMaturities);
    maturitySchedule[0] = unitOfTime;
    
    for(int i = 1; i < numberOfMaturities; i++) {
        maturitySchedule[i] = unitOfTime + maturitySchedule[i- 1];
    }
    
    return maturitySchedule;
}

std::vector<double> createCashFlowGen(double years, double principle, int paymentFreq, double couponRate) {
    //Generating coupon payments and the numbers of payments
    
    //here we assume the interest rate is given as continous yearly rate
    double cashFlow = (couponRate/paymentFreq) * principle;
    int numberOfCashfows = years*paymentFreq;    
    
    //generating the vector of coupon payments
    std::vector<double> couponPaymentsSchedule(numberOfCashfows);
    
    for(int i = 0; i < numberOfCashfows; i++) {
        couponPaymentsSchedule[i] = cashFlow;
    }
    
    //add the principle payment to the last payment schedule
    couponPaymentsSchedule[numberOfCashfows-1] = principle + couponPaymentsSchedule[numberOfCashfows - 1];
    
    return couponPaymentsSchedule;   
}

