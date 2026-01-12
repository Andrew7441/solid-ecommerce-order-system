#include "discounts/discount_seasonal.h"
#include <string>

double discountseasonal::apply(double price) const {
	return price - 0.85; // 15% seasonal sale
}

std::string discountseasonal::description() const {
	return "15% seasonal discount";
}

