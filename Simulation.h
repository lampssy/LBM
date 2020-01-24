#pragma once
#include <vector>
#include "Node.h"
#include "VelocitySet.h"

using namespace std;

class Simulation
{
private:
	void collision(Node node, const VelocitySet& velSet, vector<Node>& nodes);
	void stream(const VelocitySet& velSet, vector<Node>& nodes);

public:
	Simulation();
	~Simulation();
	
	void iterate();
};

