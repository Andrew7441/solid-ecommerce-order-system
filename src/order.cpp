#include "order.h"

order::order(const std::string& id, const std::vector<product> products) 
	: id{ id }, totalprice(0.0), status(orderstatus::Pending), products{ products } {
	calculateTotal();
}

void order::calculateTotal() {
	totalprice = 0.0;

	for (const auto& p : products)
		totalprice += p.getprice();
}

double order::get_total() const {
	return totalprice;
}

const std::vector<product>& order::getproducts() const {
	return products;
}

orderstatus order::getstatus() const {
	return status;
}

void order::setstatus(orderstatus status) {
	this->status = status;
}