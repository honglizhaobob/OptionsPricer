#ifndef AmericanOption_h
#define AmericanOption_h

#include "Option.h"
#include <vector>
#include <algorithm>
#include <cmath>

class AmericanOption : public Option {
public:
    // constructor
    AmericanOption(double _strike, double _underlying, double _maturity, double _riskFreeRate, double _volatility, bool _isCall)
        : Option(_strike, _underlying, _maturity, _riskFreeRate, _volatility, _isCall) {}

    // default binomial tree with 1000 steps
    double price() const override {
        return binomialTree(1000);  // default 1000 steps
    }

    // overloaded binomial tree with custom steps
    double price(int steps) const {
        return binomialTree(steps);
    }

private:
    double binomialTree(int steps) const {
        // time step size
        double dt = maturity / steps;

        // up and down factors
        double u = std::exp(volatility * std::sqrt(dt));
        double d = 1 / u;

        // risk-neutral probability
        double p = (std::exp(riskFreeRate * dt) - d) / (u - d);

        std::vector<double> prices(steps + 1);
        std::vector<double> values(steps + 1);

        // initialize terminal values for call or put options
        for (int i = 0; i <= steps; ++i) {
            prices[i] = underlying * std::pow(u, steps - i) * std::pow(d, i);
            values[i] = isCall ? std::max(0.0, prices[i] - strike) : std::max(0.0, strike - prices[i]);
        }

        // step back through the binomial tree
        for (int j = steps - 1; j >= 0; --j) {
            for (int i = 0; i <= j; ++i) {
                prices[i] = underlying * std::pow(u, j - i) * std::pow(d, i);  // recompute price at step j

                // value = max of holding value and intrinsic value (for early exercise)
                double holdValue = std::exp(-riskFreeRate * dt) * (p * values[i] + (1 - p) * values[i + 1]);
                double intrinsicValue = isCall ? std::max(0.0, prices[i] - strike) : std::max(0.0, strike - prices[i]);

                // allow early exercise
                values[i] = std::max(holdValue, intrinsicValue);
            }
        }

        return values[0];  // return option price at the root
    }
};

#endif /* AmericanOption_h */
