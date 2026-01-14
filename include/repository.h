#pragma once

#include "order.h"
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

