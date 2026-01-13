#pragma once
#include <string>

class product {
private:
	std::string name;
	std::string category;
	double price;
public:
	product(const std::string& name, const std::string& category, double price);

	const std::string& getname() const;
	const std::string& getcategory() const;
	double getprice() const;
};