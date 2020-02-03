#pragma once

#include "InternalNode.h"
#include "VelocitySet.h"
#include "Domain.h"


class Simulation
{
private:
	void Collision(const VelocitySet& velSet, std::vector<std::vector<Node>>& nodes, double relaxation);
	void Streaming(const VelocitySet& velSet, std::vector<std::vector<Node>>& nodes, Domain domain);

public:
	Simulation();
	~Simulation();
	
	void iterate();
};

