#include "Domain.h"


Domain::Domain(const VelocitySet& velSet, const std::vector<size_t>& domainSize, int cylinderX0, int cylinderY0, int radius)
	:	m_velSet(velSet), m_domainSize(domainSize), m_cylinderX0(cylinderX0), m_cylinderY0(cylinderY0), m_radius(radius)
{
}


Domain::~Domain()
{
}


void Domain::CreateNodes()
{
	int maxY = m_domainSize[1] - 1;
	int maxX = m_domainSize[0] - 1;
	m_lattice.reserve(maxY + 1);
	for (int coord_y = 1; coord_y < maxY; coord_y++)
	{
		m_lattice[coord_y].reserve(maxX + 1);
		for (int coord_x = 1; coord_x < maxX; coord_x++)
		{
			if (Distance(coord_x, coord_y) > m_radius)
				m_lattice[coord_y].emplace_back(InternalNode());	// creating internal nodes
			if (Distance(coord_x, coord_y) == m_radius)
				m_lattice[coord_y].emplace_back(Wall(coord_x, coord_y));	// creating wall nodes for the cylinder
		}	// std::vector m_lattice has empty elements (coordinates inside the cylinder) - not optimal solution?
	}
	for (int coord_x = 1; coord_x < maxX; coord_x++)
	{
		m_lattice[0].emplace_back(Wall(coord_x, 0));			// creating lower wall nodes
		m_lattice[maxY].emplace_back(Wall(coord_x, maxY));	// creating upper wall nodes
	}
	// loop for inlet
	// loop for outflow
}

bool Domain::IsInDomain(int coord_x, int coord_y) const
{
	if (coord_x >= 0 && coord_x < m_domainSize[0] && coord_y >= 0 && coord_y < m_domainSize[1])
		return 1;
	else
		return 0;
}

double Domain::Distance(int x, int y)
{
	return sqrt((m_cylinderX0 - x)*(m_cylinderX0 - x) + (m_cylinderY0 - y)*(m_cylinderY0 - y));
}
