#pragma once

#include "VelocitySet.h"

class D2Q9 : public VelocitySet
{
public:
	D2Q9();
	~D2Q9();

	int OppositeDirection(int dir) const override;
};

