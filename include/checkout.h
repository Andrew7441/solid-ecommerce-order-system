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
