#include "Wall.h"

Wall::Wall(int x, int y)
	:	m_coordX(x), m_coordY(y)
{
}


Wall::~Wall()
{
}


void Wall::Stream(const VelocitySet& velSet, Node* neighbour, size_t dir, Domain domain)
{
	if (IsBounceBack(velSet, dir, domain))	//	check whether bounceback occurs for this direction, if yes - m_newDistribution[dir] should be assigned to neighbour.m_distribution[opp_dir]
	{
		size_t opp_dir = velSet.OppositeDirection(dir);
		neighbour->m_distributions[opp_dir] = this->m_newDistributions[dir];
	}
	else
		neighbour->m_distributions[dir] = this->m_newDistributions[dir];
}

bool Wall::IsBounceBack(const VelocitySet& velSet, size_t dir, const Domain& domain)
{
	int dirX = velSet.getDirection(dir)[0];
	int dirY = velSet.getDirection(dir)[1];

	if (domain.IsInDomain(this->m_coordX + dirX, this->m_coordY + dirY))	// check whether neighbouring node (in direction dir) is within the domain - if not then bounce back
		return 0;
	else
		return 1;
}