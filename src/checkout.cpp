#include "checkout.h"
#include "order.h"

CheckoutService::CheckoutService(IorderRepository& repository, Ipaymentprocessor& paymentProcessor, Ishippingcalculator& shippingcalcultor)
    : repository_(repository), paymentProcessor_(paymentProcessor), shippingcalcultor_(shippingcalcultor)
{}

order CheckoutService::checkout(const cart& cart){
    double cartTotal = cart.gettotal();
    double shippingCost = shippingcalcultor_.calculate(cart);
    double finalTotal = cartTotal + shippingCost;
    std::string transactionID = paymentProcessor_.processPayment(finalTotal);

    if (transactionID.empty()) {
        order ord("", cart.getproducts());
        ord.setstatus(orderstatus::Failed);
        repository_.save(ord);
        return ord;
    }

    order ord(transactionID, cart.getproducts());
    ord.calculateTotal();
    ord.set_total(finalTotal + shippingCost);
    ord.setstatus(orderstatus::Paid);
    repository_.save(ord);

    return ord;
}