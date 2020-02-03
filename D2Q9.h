#pragma once

#include "VelocitySet.h"

class D2Q9 : public VelocitySet
{
public:
	D2Q9();
	~D2Q9();

	size_t OppositeDirection(size_t dir) const override;
};

