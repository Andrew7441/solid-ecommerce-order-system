#include "discount.h"
#include <string>

class discountseasonal : public discount {

public:

	virtual double apply(double price) const override;
	virtual std::string description() const override;
};