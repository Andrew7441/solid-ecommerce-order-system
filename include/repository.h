#pragma once

#include "order.h"
#include "shipping.h"
#include <vector>
#include <string>
#include <optional>

class IorderRepository {
public:
	virtual ~IorderRepository() = default;

	virtual void save(const order& order) = 0;
	virtual std::optional<order> getbyId(const std::string& id) = 0;
	virtual std::vector<order> getAll() = 0;
};

class InMemoryOrderRepository : public IorderRepository {
private:
	std::vector<order> orders;

public:
	virtual void save(const order& order) override;
	virtual std::optional<order> getbyId(const std::string& id) override;
	virtual std::vector<order> getAll() override;
};