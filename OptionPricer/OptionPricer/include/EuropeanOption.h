//
//  EuropeanOption.h
//  OptionPricer
//
//  Created by Bob Zhao on 9/17/24.
//

#ifndef EuropeanOption_h
#define EuropeanOption_h

#include "Option.h"

class EuropeanOption : public Option {
public:
    // constructor
    EuropeanOption(double _strike, double _underlying, double _maturity, double _riskFreeRate, double _volatility) : Option(_strike, _underlying, _maturity, _riskFreeRate, _volatility) {}
    
    // implement Black-Scholes
    double price() const override {
        return blackScholes();
    }
    
private:
    double blackScholes() const {
        // calculate d1 and d2 from the analytic solution
        double d1 = (std::log(underlying / strike) + (riskFreeRate + 0.5 * volatility * volatility) * maturity) / (volatility * std::sqrt(maturity));
        double d2 = d1 - volatility * std::sqrt(maturity);
        
        // evaluate cumulative normal distribution
        double Nd1 = normalCDF(d1);
        double Nd2 = normalCDF(d2);
        
        // formula
        double callPrice = underlying * Nd1 - strike * std::exp(-riskFreeRate * maturity) * Nd2;
        return callPrice;
    }
    
    double normalCDF(double x) const {
        /* Helper function for normal cumulative distribution function*/
        return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
    }
};

#endif /* EuropeanOption_h */
