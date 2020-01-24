#include "Simulation.h"
#include "Domain.h"


Simulation::Simulation()
{
}

Simulation::~Simulation()
{
}

void Simulation::iterate()
{
	collision();	
	stream();	
}

void Simulation::collision(Node node, const VelocitySet& velSet, vector<Node>& nodes)
{
	for (size_t dir = 0; dir < velSet.get_nDirections; dir++)
	{
		for (auto node : nodes)
		{
			// fout = fi + 1/tau(fi - feq)
		}
	}

}

void Simulation::stream(const VelocitySet& velSet, vector<Node>& nodes)
{
	for (size_t dir = 0; dir < velSet.get_nDirections; dir++)
	{
		for (auto node : nodes)
		{
			// Domain::m_nodes[x + ex][y + ey].fin = Domain::m_nodes[x][y].fout
		}
	}
}