#pragma once
#include "discount.h"
#include "product.h"
#include <vector>
#include <memory>

class cart {
private:
	std::vector<product> products;
	std::vector<std::shared_ptr<discount>> discounts;

public:
	void addproduct(const product& product);
	void addDiscount(std::shared_ptr<discount> discount);

	double gettotal() const;
};