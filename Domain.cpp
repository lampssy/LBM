#include "Domain.h"


Domain::Domain(std::shared_ptr<VelocitySet> velSet, const std::vector<int> domainSize, int cylinderX0, int cylinderY0, int radius)
	: m_velSet(velSet), m_domainSize(domainSize), m_cylinderX0(cylinderX0), m_cylinderY0(cylinderY0), m_radius(radius)
{
}


Domain::~Domain()
{
}


void Domain::Initialize()
{
	for (auto node_ptr : m_lattice)
	{
		if (node_ptr != nullptr)
		{
			node_ptr->m_distributions.reserve(m_velSet->Get_nDirections());
			for (int dir = 0; dir < m_velSet->Get_nDirections(); dir++)
			{
				node_ptr->m_distributions.push_back(m_velSet->GetWeight(dir));
				node_ptr->m_newDistributions.push_back(m_velSet->GetWeight(dir));
			}
		}
	}
}

void Domain::ConnectNodes()
{
	for (auto node_ptr : m_lattice)
	{
		//node_ptr->m_neighbours.reserve(m_velSet->Get_nDirections());
		if (node_ptr != nullptr)
		{
			node_ptr->m_neighbours[0] = nullptr;		// no neighbour in the 0 direction
			for (int dir = 1; dir < m_velSet->Get_nDirections(); dir++)
			{
				int x_neighbour = node_ptr->x_position + m_velSet->GetDirection(dir)[0];
				int y_neighbour = node_ptr->y_position + m_velSet->GetDirection(dir)[1];
				if (IsInDomain(x_neighbour, y_neighbour))
				{
					int idx_neighbour = y_neighbour * m_domainSize[0] + x_neighbour;
					//td::shared_ptr<Node> neighbour_ptr = m_lattice[idx_neighbour];
					//memcpy(&neighbour_ptr, &m_lattice[idx_neighbour], sizeof(std::shared_ptr<Node>));
					node_ptr->m_neighbours[dir] = m_lattice[idx_neighbour];
				}
				else
					node_ptr->m_neighbours[dir] = nullptr;
			}
		}
	}
}

void Domain::CreateNodes()
{
	int max_nNodes = m_domainSize[1] * m_domainSize[0];
	m_lattice.reserve(max_nNodes);
	for (int coord_y = 0; coord_y < m_domainSize[1]; coord_y++)
	{
		m_lattice.push_back(std::make_shared<ZouHe>(0, coord_y));			// creating pointers to inlet nodes
		for (int coord_x = 1; coord_x < m_domainSize[0]; coord_x++)
		{
			if (Distance(coord_x, coord_y) >= m_radius)
				m_lattice.push_back(std::make_shared<Node>(coord_x, coord_y));		// creating pointers to internal and wall nodes
			else
				m_lattice.push_back(nullptr);
		}
	}
}

bool Domain::IsInDomain(int coord_x, int coord_y)
{
	if (coord_x >= 0 && coord_x < m_domainSize[0] && coord_y >= 0 && coord_y < m_domainSize[1] && Distance(coord_x, coord_y) >= m_radius)
		return 1;
	else
		return 0;
}

double Domain::Distance(int x, int y)
{
	return sqrt((m_cylinderX0 - x)*(m_cylinderX0 - x) + (m_cylinderY0 - y)*(m_cylinderY0 - y));
}

const std::shared_ptr<VelocitySet> Domain::GetVelSet()
{
	return m_velSet;
}