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
    bool isCall;  // true for call, false for put
    
public:
    // constructor
    Option(double _strike, double _underlying, double _maturity, double _riskFreeRate, double _volatility, bool _isCall)
        : strike(_strike), underlying(_underlying), maturity(_maturity), riskFreeRate(_riskFreeRate), volatility(_volatility), isCall(_isCall) {}
    
    // virtual destructor to ensure proper cleanup of derived classes
    virtual ~Option() {}
    
    // virtual function to be overridden for specific options
    virtual double price() const = 0;

    // getter for option type
    bool getIsCall() const {
        return isCall;
    }
    
    // getter for other option properties
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
    
    // print option details
    virtual void display() const {
        std::cout << "===========================\n";
        std::cout << "      Option Properties     \n";
        std::cout << "===========================\n";
        std::cout << (isCall ? "Option Type:     Call\n" : "Option Type:     Put\n");
        std::cout << "Strike Price:    " << strike << "\n";
        std::cout << "Underlying Price:" << underlying << "\n";
        std::cout << "Maturity:        " << maturity << " year(s)\n";
        std::cout << "Risk-Free Rate:  " << riskFreeRate * 100 << "%\n";
        std::cout << "Volatility:      " << volatility * 100 << "%\n";
        std::cout << "===========================\n";
    }
};

#endif /* Option_h */
