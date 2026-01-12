#pragma once
#include "discount.h"
#include <string>

class discountcoupon : public discount {
	double amount;

public:
	explicit discountcoupon(double amount);
	virtual double apply(double price) const override;
	virtual std::string description() const override;
};