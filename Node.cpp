#include "Node.h"

Node::Node()
{
}


Node::~Node()
{
}

double Node::Equilibrium(const VelocitySet& velSet, size_t dir)
{
	// feq[i] = weight[i] * rho * (1 + (dir[i]*u)/c^2 + (dir[i]*u)^2/2c^4 - u^2/2c^2)
	double du = Velocity(velSet, dir)[0] * velSet.getDirection(dir)[0] + Velocity(velSet, dir)[1] * velSet.getDirection(dir)[1];
	double u_sqr = Velocity(velSet, dir)[0] * Velocity(velSet, dir)[0] + Velocity(velSet, dir)[1] * Velocity(velSet, dir)[1];

	return velSet.getWeight(dir) * Density() * (1 + 3 * du + 3 / 2 * du * du - 3 / 2 * u_sqr);
}

double Node::Density()
{
	double density = 0;
	for (size_t dir = 0; dir < m_distributions.size(); dir++)
	{
		density += this->m_distributions[dir];	// sum of distributions for all discrete velocities (in all directions)
	}
	return density;
}

std::vector<double> Node::Velocity(const VelocitySet& velSet, size_t dir)
{
	std::vector<double> velocity;
	velocity.reserve(2);	// 2D case
	for (size_t dim = 0; dim < 2; dim++)
	{
		velocity[dim] += velSet.getDirection(dir)[dim] * this->m_distributions[dir];
	}

	for (size_t dim = 0; dim < 2; dim++)
	{
		velocity[dim] /= Density();
	}

	return velocity;
}
