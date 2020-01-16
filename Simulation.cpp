#include "Simulation.h"

Simulation::Simulation(const vector<vector<double>>& RHO, const vector<vector<vector<double>>>& U, const vector<vector<vector<double>>>& FIN, const vector<vector<int>>& C)
{
}

Simulation::~Simulation()
{
}

void Simulation::iterate()
{
	collision();	//velocity set and nodes vector initialized while creating domain
	stream();		//velocity set and nodes vector initialized while creating domain
}