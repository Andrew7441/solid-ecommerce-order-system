#pragma once
#include "cart.h"
class cart;

class Ishippingcalculator {
public:
	virtual double calculate(const cart& crt) const = 0;
	virtual ~Ishippingcalculator() = default;
};

class FlatRateShippingCalculator : public Ishippingcalculator {
private:
	double rate;
public:
	explicit FlatRateShippingCalculator(double rate);
	virtual double calculate(const cart& crt) const override;
};