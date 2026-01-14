#include "repository.h"


class InMemoryOrderRepository : IorderRepository {
private:
	std::vector<order> orders;

public:
	virtual void save(const order& order) {
		orders.push_back(order);
	}

	virtual std::optional<order> getbyId(const std::string& id) {
		for (const auto& o : orders) {
			if (o.getid() == id) {
				return o;
			}
		}
		return std::nullopt;
	}

	virtual std::vector<order> getAll() {
		return orders;
	}
};