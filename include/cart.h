#pragma once
#include "discount.h"
#include "Product.h"
#include <vector>
#include <memory>

class Cart {
private:
	std::vector<Product> products;
	std::vector<std::shared_ptr<discount>> discounts;

public:
	void addProduct(const Product& product);
	void addDiscount(std::shared_ptr<discount> discount);

	double gettotal() const;
};