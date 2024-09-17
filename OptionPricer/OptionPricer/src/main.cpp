//
//  main.cpp
//  OptionPricer
//
//  Created by Bob Zhao on 9/17/24.
//

#include <iostream>
#include "EuropeanOption.h"

int main() {
    // quick testing of Black Scholes
    double strikePrice = 100.0;
    double underlyingPrice = 105.0;
    double maturity = 1.0;
    double riskFreeRate = 0.05;
    double volatility = 0.2;
    
    EuropeanOption callOption(strikePrice, underlyingPrice, maturity, riskFreeRate, volatility);
    // price it
    double callPrice = callOption.price();
    
    callOption.display();
    
    std::cout << "Call Option Price = " << callPrice << "\n";
    
    return 0;
}

