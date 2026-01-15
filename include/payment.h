#pragma once

#include <string>

class Ipaymentprocessor { // Interface 
public:
	virtual std::string processPayment(double amount) = 0;
	virtual ~Ipaymentprocessor() = default;

};

class PaymentProcessor : public Ipaymentprocessor {
private:
	static int nextId;

public:	
	virtual std::string processPayment(double amount);
};