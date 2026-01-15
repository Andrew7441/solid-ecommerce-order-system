#include "payment.h"
#include <string>

int PaymentProcessor::nextId = 1;

std::string PaymentProcessor::processPayment(double amount) {
	return "$" + std::to_string(nextId++);
}