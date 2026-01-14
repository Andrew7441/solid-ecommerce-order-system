#include "shipping.h"
#include "cart.h"

FlatRateShippingCalculator::FlatRateShippingCalculator(double rate)
	: rate{rate} { }

double FlatRateShippingCalculator::calculate(const cart& crt) const {
	(void)crt;
	return rate;
}


