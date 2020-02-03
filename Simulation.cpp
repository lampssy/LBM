#include "Simulation.h"


Simulation::Simulation()
{
}

Simulation::~Simulation()
{
}

void Simulation::iterate()
{
	Collision();	
	Streaming();	
}

void Simulation::Collision(const VelocitySet& velSet, std::vector<std::vector<Node>>& nodes, double relaxation)
{
	for (auto row : nodes)
	{
		for (auto node : row)
		{
			for (size_t dir = 0; dir < velSet.get_nDirections; dir++)
			{
				node.m_newDistributions[dir] = node.m_distributions[dir] - 1 / relaxation * (node.m_distributions[dir] - node.Equilibrium(velSet, dir));	// applying BGK approximation
			}
		}
	}
}

void Simulation::Streaming(const VelocitySet& velSet, std::vector<std::vector<Node>>& nodes, Domain domain)
{
	for (int coord_y = 0; coord_y < nodes.size(); coord_y++)
	{
		for (int coord_x = 0; coord_x < nodes[coord_y].size(); coord_x++)
		{
			bool isBoundary = 0;
			for (size_t dir = 0; dir < velSet.get_nDirections; dir++)
			{
				int y_neighbour = coord_y + velSet.getDirection[dir][1];
				int x_neighbour = coord_x + velSet.getDirection[dir][0];
				if (domain.IsInDomain(x_neighbour, y_neighbour))
				{
					Node* neighbour_ptr = &nodes[y_neighbour][x_neighbour];
					nodes[coord_y][coord_x].Stream(velSet, neighbour_ptr, dir);
				}
			}
		}
	}
}