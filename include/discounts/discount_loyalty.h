#include "discount.h"
#include <string>

class discountloyalty : public discount {
	double percentage;
public:
	discountloyalty(double percentage);
	virtual double apply(double amount) const override;
	virtual std::string description() const override;
};

