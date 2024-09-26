//
//  main.cpp
//  OptionPricer
//
//  Created by Bob Zhao on 9/17/24.
//

#include <iostream>
#include "EuropeanOption.h"
#include "AmericanOption.h"
int main() {
    // set parameters for call options
    double strikePrice = 100.0;
    double underlyingPrice = 105.0;
    double maturity = 1.0;
    double riskFreeRate = 0.05;
    double volatility = 0.2;
    
    // European option
    EuropeanOption europeanCall(strikePrice, underlyingPrice, maturity, riskFreeRate, volatility);
    double europeanCallPrice = europeanCall.price();
    europeanCall.display();
    std::cout << "European call option price = " << europeanCallPrice << "\n\n";
    
    
    // American option
    AmericanOption americanCall(strikePrice, underlyingPrice, maturity, riskFreeRate, volatility);
    double americanCallPrice = americanCall.price();
    americanCall.display();
    std::cout << "American call option price = " << americanCallPrice << "\n\n";
    
    
    
    
    
    
    
    
    
    return 0;
}

