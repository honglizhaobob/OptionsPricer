#ifndef BermudaOption_h
#define BermudaOption_h

#include "Option.h"
#include <vector>
#include <algorithm>
#include <cmath>

class BermudaOption : public Option {
public:
    // constructor that accepts the exercise dates
    BermudaOption(double _strike, double _underlying, double _maturity, double _riskFreeRate, double _volatility, bool _isCall, const std::vector<double>& _exerciseDates)
        : Option(_strike, _underlying, _maturity, _riskFreeRate, _volatility, _isCall), exerciseDates(_exerciseDates) {}

    // price the option using the binomial tree
    double price() const override {
        return binomialTree(1000);  // default 1000 steps
    }

    // overloaded price method to allow custom number of steps
    double price(int steps) const {
        return binomialTree(steps);
    }

private:
    std::vector<double> exerciseDates;  // specific dates where early exercise is allowed

    // binomial tree pricing method
    double binomialTree(int steps) const {
        double dt = maturity / steps;  // time step size
        double u = std::exp(volatility * std::sqrt(dt));  // up factor
        double d = 1 / u;  // down factor
        double p = (std::exp(riskFreeRate * dt) - d) / (u - d);  // risk-neutral probability

        std::vector<double> prices(steps + 1);
        std::vector<double> values(steps + 1);

        // initialize terminal values
        for (int i = 0; i <= steps; ++i) {
            prices[i] = underlying * std::pow(u, steps - i) * std::pow(d, i);
            values[i] = isCall ? std::max(0.0, prices[i] - strike) : std::max(0.0, strike - prices[i]);
        }

        // step back through the binomial tree
        for (int j = steps - 1; j >= 0; --j) {
            for (int i = 0; i <= j; ++i) {
                prices[i] = underlying * std::pow(u, j - i) * std::pow(d, i);  // recompute price at step j

                double holdValue = std::exp(-riskFreeRate * dt) * (p * values[i] + (1 - p) * values[i + 1]);
                double intrinsicValue = isCall ? std::max(0.0, prices[i] - strike) : std::max(0.0, strike - prices[i]);

                // allow early exercise only on specified dates
                if (isExerciseDate(j, dt)) {
                    values[i] = std::max(holdValue, intrinsicValue);  // early exercise if it benefits the holder
                } else {
                    values[i] = holdValue;  // no early exercise
                }
            }
        }

        return values[0];  
    }

    // helper function to check if the current step matches any of the exercise dates
    bool isExerciseDate(int step, double dt) const {
        double time = step * dt;
        return std::find(exerciseDates.begin(), exerciseDates.end(), time) != exerciseDates.end();
    }
};

#endif /* BermudaOption_h */
