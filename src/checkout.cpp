#include "checkout.h"
#include "order.h"

CheckoutService::CheckoutService(IorderRepository& repository, Ipaymentprocessor& paymentProcessor, Ishippingcalculator& shippingcalcultor)
    : repository_(repository), paymentProcessor_(paymentProcessor), shippingcalcultor_(shippingcalcultor)
{}

order CheckoutService::checkout(const cart& cart) {
    double cartTotal = cart.gettotal();
    double shippingCost = shippingcalcultor_.calculate(cart);

    double finalTotal = cartTotal + shippingCost;

    std::string transactionID = paymentProcessor_.processPayment(finalTotal);

    // Create order using the available constructor
    order ord(transactionID, cart.getproducts());

    ord.setstatus(orderstatus::Paid);
    ord.calculateTotal();

    repository_.save(ord);

    return ord;
}