#include "cart.h"

void cart::addproduct(const product& product) {
	products.push_back(product);
}

void cart::addDiscount(std::shared_ptr<discount> discount) {
	discounts.push_back(discount);
}

double cart::gettotal() const {
	double total{ 0.0 };

	for (const auto& p : products) {
		total += p.getprice();
	}

	for (const auto& d : discounts) {
		total = d->apply(total);
	}

	return total;
}

std::vector<product> cart::getproducts() const {
	return products;
}