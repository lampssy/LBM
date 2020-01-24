#include "Node.h"
#include "Domain.h"


Node::Node(int x, int y)
	:	m_x(x), m_y(y)
{
}


Node::~Node()
{
}


double Node::Distribution()
{
	for (int dir = 0; dir < m_distributions.size(); dir++)
	{
		m_newDistribution[dir] = m_distributions[dir] + 1 / 2 * (m_distributions[dir] - Equilibrium());
	}

}

double Node::Equilibrium(const VelocitySet& velSet, size_t dir)
{
	// return velSet.getWeight(dir) * Density() * (1 + ...)
}

double Node::Density()
{
	double density = 0;
	for (size_t dir = 0; dir < m_distributions.size(); dir++)
	{
		density += this->m_distributions[dir];
	}
	return density;
}

std::vector<double> Node::Velocity(const VelocitySet& velSet, size_t dir)
{
	std::vector<double> velocity(2, 0);
	for (size_t dim = 0; dim < 2; dim++)
	{
		velocity[dim] += velSet.getDirection(dir)[dim] * this->m_distributions[dir];
	}
	return velocity;
}