#include <iostream>
#include <memory>
#include "discount.h"
#include "cart.h"
#include "product.h"
#include "order.h"
#include "repository.h"
#include "payment.h"
#include "shipping.h"
#include "checkout.h"
#include "discounts/discount_seasonal.h"
#include "discounts/discount_coupon.h"
#include "discounts/discount_loyalty.h"

int main() {

	product p1("Macbook Pro", "Electronics", 2000.0);

	cart myCart;

	myCart.addproduct(p1);

	myCart.addDiscount(std::make_shared<discountseasonal>()); 

	InMemoryOrderRepository repo;									// Implements IorderRepository
	PaymentProcessor paymentProcessor;								// Implements Ipaymentprocessor
	FlatRateShippingCalculator shippingCalc(15.0);					// Implements Ishippingcalculator

	CheckoutService checkoutService(repo, paymentProcessor, shippingCalc);

	order ord = checkoutService.checkout(myCart);
	std::cout << "Product:\nName: " << p1.getname()
		<< "\nCategory: " << p1.getcategory()
		<< "\nPrice: " << p1.getprice() << std::endl;

	std::cout << "Order ID: " << ord.getid() << std::endl;
	std::cout << "Order Total: " << ord.get_total() << std::endl;
	std::cout << "Order Status: ";
	
	switch (ord.getstatus()) {
		case orderstatus::Pending: std::cout << "Pending\n"; break;
		case orderstatus::Failed: std::cout << "Failed\n"; break;
		case orderstatus::Paid: std::cout << "Paid\n"; break;
		default: std::cout << "Unknown\n"; break;
	}

	return 0;
}