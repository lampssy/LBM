#pragma once
#include <vector>
#include "Node.h"
#include "VelocitySet.h"

using namespace std;

class Simulation
{
private:
	void collision(const VelocitySet& velSet, vector<Node>& nodes);
	void stream(const VelocitySet& velSet, vector<Node>& nodes);

public:
	Simulation(const vector<vector<double>>& RHO, const vector<vector<vector<double>>>& U, const vector<vector<vector<double>>>& FIN, const vector<vector<int>>& C);
	~Simulation();
	
	void iterate();
};

