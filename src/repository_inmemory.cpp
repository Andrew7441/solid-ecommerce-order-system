#include "repository.h"

void InMemoryOrderRepository::save(const order& order) {
	orders.push_back(order);
}

std::optional<order> InMemoryOrderRepository::getbyId(const std::string& id) {
	for (const auto& o : orders) {
		if (o.getid() == id) {
			return o;
		}
	}
	return std::nullopt;
}

std::vector<order> InMemoryOrderRepository::getAll() {
	return orders;
}