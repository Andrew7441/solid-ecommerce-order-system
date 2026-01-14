#pragma once
#include "product.h"
#include <string>
#include <vector>

enum class orderstatus {
	Pending, 
	Paid, 
	Failed
};

class order {
private:
	std::string id;
	std::vector<product> products;
	double totalprice;
	orderstatus status;

public:
	order(const std::string& id, const std::vector<product> products);
	void calculateTotal();
	double get_total() const;
	const std::vector<product>& getproducts() const;
	orderstatus getstatus() const;
	void setstatus(orderstatus status);
};