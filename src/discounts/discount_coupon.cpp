#include "discounts/discount_coupon.h"
#include <string>

discountcoupon::discountcoupon(double amount) : amount{amount} {}

double discountcoupon::apply(double price) const {
	return price - amount; 
}

std::string discountcoupon::description() const {
	return "$" + std::to_string(static_cast<int>(amount)) + " coupon";
}

