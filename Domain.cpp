#include "Domain.h"


Domain::Domain(const VelocitySet& velSet, const vector<size_t>& domainSize)
	:	m_velSet(velSet), m_domainSize(domainSize)
{
}


Domain::~Domain()
{
}


void Domain::CreateNodes()
{
	m_nodes[m_domainSize[1]];
	for (int coord_y = 0; coord_y < m_domainSize[0]; coord_y++)
	{
		m_nodes[coord_y][m_domainSize[0] - 1];
		for (int coord_x = 0; coord_x < m_domainSize[0]; coord_x++)
		{
			Node node(coord_x, coord_y);
			m_nodes[coord_y].push_back(node);
		}
	}
}

Node Domain::InitializeNode(std::vector<double> coordinates)
{

}