//
//  Option.h
//  OptionPricer
//
//  Created by Bob Zhao on 9/17/24.
//

#ifndef Option_h
#define Option_h

#include <iostream>
#include <cmath>
#include <string>

class Option {
protected:
    double strike;
    double underlying;
    double maturity;
    double riskFreeRate;
    double volatility;
    
public:
    // constructor
    Option(double _strike, double _underlying, double _maturity, double _riskFreeRate, double _volatility) : strike(_strike), underlying(_underlying), maturity(_maturity), riskFreeRate(_riskFreeRate), volatility(_volatility) {}
    
    // virtual destructor to ensure proper cleanup of derived classes
    virtual ~Option() {}
    
    // virtual function to be overridden for specific options
    virtual double price() const = 0;
    
    // getter
    double getStrike() const {
        return strike;
    }
    double getUnderlying() const {
        return underlying;
    }
    double getMaturity() const {
        return maturity;
    }
    double getRiskFreeRate() const {
        return riskFreeRate;
    }
    double getVolatility() const {
        return volatility;
    }
    
    // verbose print details
    virtual void display() const {
        std::cout << "Option Properties \n";
        std::cout << "*> Strike = " << strike << "\n";
        std::cout << "*> Underlying Price = " << underlying << "\n";
        std::cout << "*> Maturity (Yr) = " << maturity << "\n";
        std::cout << "*> Risk Free Rate = " << riskFreeRate << "\n";
        std::cout << "*> Volatility = " << volatility << "\n";
    }
};

#endif /* Option_h */
