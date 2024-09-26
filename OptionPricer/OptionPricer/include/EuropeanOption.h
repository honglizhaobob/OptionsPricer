#ifndef EuropeanOption_h
#define EuropeanOption_h

#include "Option.h"
#include <cmath>

class EuropeanOption : public Option {
public:
    // constructor
    EuropeanOption(double _strike, double _underlying, double _maturity, double _riskFreeRate, double _volatility, bool _isCall)
        : Option(_strike, _underlying, _maturity, _riskFreeRate, _volatility, _isCall) {}
    
    // implement Black-Scholes formula
    double price() const override {
        return isCall ? blackScholesCall() : blackScholesPut();
    }

private:
    // black-scholes formula for call option
    double blackScholesCall() const {
        double d1 = (std::log(underlying / strike) + (riskFreeRate + 0.5 * volatility * volatility) * maturity) / (volatility * std::sqrt(maturity));
        double d2 = d1 - volatility * std::sqrt(maturity);
        double Nd1 = normalCDF(d1);
        double Nd2 = normalCDF(d2);
        return underlying * Nd1 - strike * std::exp(-riskFreeRate * maturity) * Nd2;
    }

    // black-scholes formula for put option
    double blackScholesPut() const {
        double d1 = (std::log(underlying / strike) + (riskFreeRate + 0.5 * volatility * volatility) * maturity) / (volatility * std::sqrt(maturity));
        double d2 = d1 - volatility * std::sqrt(maturity);
        double Nd1 = normalCDF(-d1);  // negating for put
        double Nd2 = normalCDF(-d2);  // negating for put
        return strike * std::exp(-riskFreeRate * maturity) * Nd2 - underlying * Nd1;
    }

    // normal cumulative distribution function (CDF)
    double normalCDF(double x) const {
        return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
    }
};

#endif /* EuropeanOption_h */
