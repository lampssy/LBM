#include "Node.h"

Node::Node(int coord_x, int coord_y)
	:	x_position(coord_x), y_position(coord_y)
{
}


Node::~Node()
{
}

void Node::Stream(int dir)
{
	if (dir == 0)
		m_distributions[dir] = m_newDistributions[dir];
	else
		m_neighbours[dir]->m_distributions[dir] = m_newDistributions[dir];
}

double Node::Equilibrium(std::shared_ptr<VelocitySet> velSet, int dir)
{
	// feq[i] = weight[i] * rho * (1 + (dir[i]*u)/c^2 + (dir[i]*u)^2/2c^4 - u^2/2c^2)
	double du = Velocity(velSet)[0] * velSet->GetDirection(dir)[0] + Velocity(velSet)[1] * velSet->GetDirection(dir)[1];
	double u_sqr = Velocity(velSet)[0] * Velocity(velSet)[0] + Velocity(velSet)[1] * Velocity(velSet)[1];

	return velSet->GetWeight(dir) * Density() * (1 + 3 * du + 9 / 2 * du * du - 3 / 2 * u_sqr);
}

double Node::Initialize(std::shared_ptr<VelocitySet> velSet, int dir)
{
	double vel_x = 0.04 * sin(double(y_position) / double(149) * PI);
	double rho = 1;
	double du = vel_x * velSet->GetDirection(dir)[0];
	double u_sqr = vel_x * vel_x;

	m_distributions.push_back(velSet->GetWeight(dir) * rho * (1 + 3 * du + 9 / 2 * du * du - 3 / 2 * u_sqr));
	m_newDistributions.push_back(0);
}

double Node::Density()
{
	double density = 0;
	for (int dir = 0; dir < 9; dir++)
	{
		density += this->m_distributions[dir];	// sum of distributions for all discrete velocities (in all directions)
	}
	return density;
}

std::vector<double> Node::Velocity(std::shared_ptr<VelocitySet> velSet)
{
	std::vector<double> velocity;
	velocity.reserve(2);	// 2D case
	velocity.push_back(0);
	velocity.push_back(0);

	for (int dir = 0; dir < 9; dir++)
	{
		for (int dim = 0; dim < 2; dim++)
		{
			velocity[dim] += velSet->GetDirection(dir)[dim] * this->m_distributions[dir];
		}
	}

	for (int dim = 0; dim < 2; dim++)
	{
		velocity[dim] /= Density();
	}

	return velocity;
}

void Node::BounceBack(int dir, int opp_dir)
{
	m_distributions[opp_dir] = m_newDistributions[dir];
}

void Node::ApplyBC()
{
}

const double Node::PI = 3.1415;