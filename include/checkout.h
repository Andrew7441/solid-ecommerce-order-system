#pragma once

#include "cart.h"
#include "payment.h"
#include "shipping.h"
#include "repository.h"

class order;

class CheckoutService {
private:
	IorderRepository& repository_;
	Ipaymentprocessor& paymentProcessor_;
	Ishippingcalculator& shippingcalcultor_;
public:
	CheckoutService(IorderRepository& repository,  
		Ipaymentprocessor& paymentProcessor,
		Ishippingcalculator& shippingcalcultor);

	order checkout(const cart& cart);
};

/*
passing in concrete implementations at runtime
interface declares the contract, concrete class implements it and polymorphism makes the call 
dispatch to the concrete implementation

This is Open-Closed Principle.
	CheckoutService depends on Ipaymentprocessor (closed for modification)
	I would add new payment types by creating new classes that implement IpaymentProcessor (open for extension)
*/