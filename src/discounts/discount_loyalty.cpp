#include "discounts/discount_loyalty.h"
#include <string>

discountloyalty::discountloyalty(double percentage) : percentage{percentage} {}

double discountloyalty::apply(double amount) const {
	return amount * (1.0 - percentage);
}

std::string discountloyalty::description() const {
	return std::to_string(static_cast<int>(percentage * 100)) + "% loyalty discount";
}

