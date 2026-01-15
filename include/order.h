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
	void setstatus(orderstatus status);
	void set_total(double total);
	double get_total() const;
	std::string getid() const;
	const std::vector<product>& getproducts() const;
	orderstatus getstatus() const;
};