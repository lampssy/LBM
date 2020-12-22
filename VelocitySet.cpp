#include "VelocitySet.h"

VelocitySet::VelocitySet(std::vector<double> weights, std::vector<std::vector<int>> directions, double cSquare)
	: m_weights(weights), m_directions(directions), m_cSquare(cSquare), m_nrOfDimensions(directions[0].size())
{
}

VelocitySet::~VelocitySet()
{
}

double VelocitySet::GetWeight(int dir) const
{
	return m_weights[dir];
}

std::vector<int> VelocitySet::GetDirection(int dir) const
{
	return m_directions[dir];
}

double VelocitySet::Get_c_square(int dir) const
{
	return m_cSquare;
}

int VelocitySet::Get_nDimensions() const
{
	return m_nrOfDimensions;
}

int VelocitySet::Get_nDirections() const
{
	return m_directions.size();
}

int VelocitySet::OppositeDirection(int dir) const
{
	return 0;
}