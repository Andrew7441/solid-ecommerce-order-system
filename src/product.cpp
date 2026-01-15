#include "product.h"
#include <string>

product::product(const std::string& name, const std::string& category, double price)
	: name{name}, category{category}, price{price} { 

}

const std::string& product::getname() const {
	return name;
}

double product::getprice() const {
	return price;
}

const std::string& product::getcategory() const {
	return category;
}
