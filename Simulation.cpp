#include "Simulation.h"

Simulation::Simulation()
{
}

Simulation::~Simulation()
{
}

void Simulation::iterate()
{
	collision();		//velocity set and nodes vector initialized while creating domain
	stream();		//velocity set and nodes vector initialized while creating domain
}
