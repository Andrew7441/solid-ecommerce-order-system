#include "cart.h"

void Cart::addProduct(const Product& product) {
	products.push_back(product);
}

void Cart::addDiscount(std::shared_ptr<discount> discount) {
	discounts.push_back(discount);
}

double Cart::gettotal() const {
	double total{ 0.0 };

	for (const auto& p : products) {
		total += p.getprice();
	}

	for (const auto& d : discounts) {
		total = d->apply(total);
	}

	return total;
}