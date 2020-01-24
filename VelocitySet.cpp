#include "VelocitySet.h"

VelocitySet::VelocitySet(vector<double> weights, vector<vector<int>> directions, double cSquare)
	:	m_weights(weights), m_directions(directions), m_cSquare(cSquare), m_nrOfDimensions(directions[0].size())
{
}

VelocitySet::~VelocitySet()
{
}

inline double VelocitySet::getWeight(size_t dir) const
{
	return m_weights[dir];
}

inline vector<int> VelocitySet::getDirection(size_t dir) const
{
	return m_directions[dir];
}

inline double VelocitySet::get_c_square(size_t dir) const
{
	return m_cSquare;
}

inline size_t VelocitySet::get_nDimensions() const
{
	return m_nrOfDimensions;
}

inline size_t VelocitySet::get_nDirections() const
{
	return m_directions.size();
}