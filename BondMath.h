#ifndef _BONDMATH_H
#define _BONDMATH_H
    
    std::vector<double> computeDiscountedCashflow(double yield, std::vector<double> maturitySchedule, std::vector<double> cashflowSchedule);
    std::vector<double> createCashFlowGen(double years, double principle, int paymentFreq, double couponRate); 
    std::vector<double> createTimeMaturitySchedule(int paymentFreq, double years);

    double compoundedToContRate(double n, int m);
    double contRateToCompounded(double n, int m);
    double fprime(double yield, std::vector<double>maturitySchedule, std::vector<double> cashflowSchedule);
    double f(double yield, double price, std::vector<double>maturitySchedule, std::vector<double> cashflowSchedule);
    double computeYieldHelper(double yield, double price, std::vector<double> maturityScheudle, std::vector<double> cashflowSchedule);
    double computeYield(std::vector<double> maturityschedule, std::vector<double> cashflowSchedule, double bondPrice);
    double computeDuration(double yield, double bondPrice, std::vector<double> maturityScheudle, std::vector<double> cashflowSchedule);
    double computeFiniteDifference(double bondPrice, double bondDuration, double difference);
    double computeDV01(double bondPrice, double bondDuration);
#endif 
