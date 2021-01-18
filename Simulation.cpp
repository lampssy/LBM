#include "Simulation.h"


Simulation::Simulation(Domain& domain)
	: m_domain(domain)
{
}

Simulation::~Simulation()
{
}

void Simulation::Iterate()
{
	Collision();
	Streaming();
	InletBC();
	OutletBC();
}

void Simulation::Collision()
{
	for (auto node_ptr : m_domain.m_lattice)
	{
		if (node_ptr != nullptr)
		{
			for (int dir = 0; dir < m_domain.GetVelSet()->Get_nDirections(); dir++)
			{
				node_ptr->m_newDistributions[dir] = node_ptr->m_distributions[dir] - 1 / m_relaxation * (node_ptr->m_distributions[dir] - node_ptr->Equilibrium(m_domain.GetVelSet(), dir));	// applying BGK approximation
			}
		}
	}
}

void Simulation::Streaming()
{
	for (auto node_ptr : m_domain.m_lattice)
	{
		if (node_ptr != nullptr)
		{
			for (int dir = 1; dir < m_domain.GetVelSet()->Get_nDirections(); dir++)
			{
				if (node_ptr->m_neighbours[dir] != nullptr)
					node_ptr->Stream(dir);
				else if (node_ptr->m_neighbours[dir] == nullptr && node_ptr->x_position != 0 && node_ptr->x_position != m_domain.m_domainSize[0] - 1)		// conditions for walls
				{
					int opp_dir = m_domain.GetVelSet()->OppositeDirection(dir);
					node_ptr->BounceBack(dir, opp_dir);
				}
			}
			//if (node_ptr->x_position == 1 && node_ptr->y_position == 75)
				//std::cout << "after streaming: " << node_ptr->Velocity(m_domain.m_velSet)[0] << "," << node_ptr->Velocity(m_domain.m_velSet)[1] << std::endl;
		}
	}
}

void Simulation::InletBC()
{
	for (int coord_y = 0; coord_y < m_domain.m_domainSize[1]; coord_y++)
	{
		int idx = coord_y * m_domain.m_domainSize[0];
		m_domain.m_lattice[idx]->ApplyBC();
	}
}

void Simulation::OutletBC()
{
	for (int coord_y = 1; coord_y <= m_domain.m_domainSize[1]; coord_y++)
	{
		int idx = coord_y * m_domain.m_domainSize[0] - 1;
		for (int dir = 1; dir < m_domain.GetVelSet()->Get_nDirections(); dir++)
			if (m_domain.m_lattice[idx]->m_neighbours[dir] == nullptr)
			{
				int opp_dir = m_domain.GetVelSet()->OppositeDirection(dir);
				m_domain.m_lattice[idx]->m_distributions[opp_dir] = m_domain.m_lattice[idx - 1]->m_distributions[opp_dir];
			}
	}
}

void Simulation::SetRelaxation(double tau)
{
	m_relaxation = tau;
}

void Simulation::WriteOutput(int iter)
{
	OutputFile file((iter));
	file.WriteCSV(m_domain.m_lattice, m_domain.m_velSet);
}