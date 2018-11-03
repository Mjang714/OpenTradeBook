#include<iostream>
#include<vector>

//here we include out custom made libraries
#include "BondMath.h"

int main(int argc, char** argv) {
    std::cout<<"Hey we are running a program right now"<<'\n';
    
    std::vector<double> cashflowSchedule = createCashFlowGen(3, 100, 2, .08);
    
    for(double cashFlow : cashflowSchedule) {
        std::cout<<cashFlow<<' ';
    } 
    std::cout<<'\n';
    
    std::vector<double> timeToMaturitySchedule = createTimeMaturitySchedule(2,3);
    for(double maturity : timeToMaturitySchedule) {
        std::cout<<maturity<<' ';
    } 
    std::cout<<'\n';

    double yield = computeYield(timeToMaturitySchedule,cashflowSchedule,150.00);
    std::cout<<"when the bond price is 150.00  we get a yield of "<<yield<<'\n';
    
    yield = computeYield(timeToMaturitySchedule,cashflowSchedule,104.00);
    std::cout<<"when the bond price is 104.00  we get a yield of "<<yield<<'\n';
    
    double durationResult  = computeDuration(yield, 104.00, timeToMaturitySchedule, cashflowSchedule);
    
    std::cout<<"The Duration of the Bond is "<<durationResult<<'\n';

    double DV01 = computeDV01(104.00, durationResult);

    std::cout<<"The DV01 for the bond is "<< DV01 <<'\n';
       
    std::cout<<"Given a compounded Rate of 7 percent compounded quartly we get a continous rate of "<<compoundedToContRate(0.07,4) * 100<<"% \n"; 
    std::cout<<"We have a continous rate of 10 percent the continous rate is "<<contRateToCompounded(.1, 12) * 100<<"% \n"; 
    return 0;
}
