#pragma once

#include <memory>

#include "HouseBuilder.h"
#include "House.h"

class HouseDirector {
public:
	HouseDirector(HouseBuilder* builder) : builder(std::shared_ptr<HouseBuilder>(builder)) {
		builder->buildHouse();
	}

	virtual ~HouseDirector() = default;

	void setBuilder(HouseBuilder* builder) {
		this->builder.reset(builder);
		this->builder->buildHouse();
	}

	House* getHouse() {
		return builder->getHouse();		
	}
private:
	std::shared_ptr<HouseBuilder> builder;
};

