#pragma once
#include <string>

class discount {
public:
	virtual double apply(double price) const = 0;
	virtual std::string description() const = 0;
	virtual ~discount() = default;
};

/*
Single Responsibility: Discount logic only
Open/Closed: add new discounts without modifying existing code
Dependency inversion: Higher-level code depends on Discount, not on concrete types 
*/

