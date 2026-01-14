#pragma once

class cart;

class Ishippingcalculator {
public:
	virtual double calculate(const cart& crt) const = 0;
	virtual ~Ishippingcalculator() = default;
};

class FlatRateShippingCalculator : Ishippingcalculator {
private:
	double rate;
public:
	explicit FlatRateShippingCalculator(double rate);
	virtual double calculate(const cart& crt) const override;
};