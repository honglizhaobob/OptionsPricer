//
//  main.cpp
//  OptionPricer
//
//  Created by Bob Zhao on 9/17/24.
//

#include <iostream>
#include "EuropeanOption.h"
#include "AmericanOption.h"
#include "BermudaOption.h"

int main() {
    // set parameters for the options
    double strikePrice = 100.0;
    double underlyingPrice = 105.0;
    double maturity = 1.0;  // 1 year
    double riskFreeRate = 0.05;  // 5%
    double volatility = 0.2;  // 20%

    // European call option
    EuropeanOption europeanCall(strikePrice, underlyingPrice, maturity, riskFreeRate, volatility, true);
    double europeanCallPrice = europeanCall.price();
    europeanCall.display();
    std::cout << "European Call Option Price = " << europeanCallPrice << "\n\n";

    // European put option
    EuropeanOption europeanPut(strikePrice, underlyingPrice, maturity, riskFreeRate, volatility, false);
    double europeanPutPrice = europeanPut.price();
    europeanPut.display();
    std::cout << "European Put Option Price = " << europeanPutPrice << "\n\n";

    // American call option
    AmericanOption americanCall(strikePrice, underlyingPrice, maturity, riskFreeRate, volatility, true);
    double americanCallPrice = americanCall.price();
    americanCall.display();
    std::cout << "American Call Option Price = " << americanCallPrice << "\n\n";

    // American put option
    AmericanOption americanPut(strikePrice, underlyingPrice, maturity, riskFreeRate, volatility, false);
    double americanPutPrice = americanPut.price();
    americanPut.display();
    std::cout << "American Put Option Price = " << americanPutPrice << "\n\n";

    // set exercise dates for Bermuda options
    std::vector<double> exerciseDates = {0.25, 0.5, 0.75};  // exercise at 3, 6, and 9 months

    // Bermuda call option
    BermudaOption bermudaCall(strikePrice, underlyingPrice, maturity, riskFreeRate, volatility, true, exerciseDates);
    double bermudaCallPrice = bermudaCall.price();
    bermudaCall.display();
    std::cout << "Bermuda Call Option Price = " << bermudaCallPrice << "\n\n";

    // Bermuda put option
    BermudaOption bermudaPut(strikePrice, underlyingPrice, maturity, riskFreeRate, volatility, false, exerciseDates);
    double bermudaPutPrice = bermudaPut.price();
    bermudaPut.display();
    std::cout << "Bermuda Put Option Price = " << bermudaPutPrice << "\n\n";

    return 0;
}
