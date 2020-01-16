#include "Domain.h"


Domain::Domain(const VelocitySet& velSet, vector<size_t> domainSize)
	:	m_velSet(velSet), m_domainSize(domainSize)
{
}


Domain::~Domain()
{
}


void Domain::CreateNodes()
{
	std::vector<Node> nodes;
	int dimensions = m_domainSize.size();
	std::vector<std::vector<int>> coordinates;
	for (size_t i = 0; i < m_domainSize[0]; i++)
	{
		for (size_t dim = 0; dim < dimensions; dim++)
		{
			for (size_t j = 0; j < m_domainSize[j]; j++)
			{
				coordinates[i][j] = 5;
			}
		}		
	}
	std::vector<
	for (size_t i = 0; i < m_domainSize[0]; i++)
	{

	}
}

Node Domain::InitializeNode(std::vector<double> position)
{
	size_t nDirections = m_velSet.get_nDirections;
	size_t nDimensions = m_velSet.get_nDimensions;

}