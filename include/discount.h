#pragma once
#include <string>

class Discount {
public:
	virtual ~Discount() = default;
	virtual double apply(double price) const = 0;
	virtual std::string description() const = 0;
};