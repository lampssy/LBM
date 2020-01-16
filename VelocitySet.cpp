#include "VelocitySet.h"

VelocitySet::VelocitySet(vector<double> weights, vector<vector<int>> directions, double cSquare)
	:	m_weights(weights), m_directions(directions), m_cSquare(cSquare), m_nDimensions()
{
}

VelocitySet::~VelocitySet()
{
}

inline double VelocitySet::getWeights(size_t idx) const
{
	return m_weights[idx];
}

inline vector<int> VelocitySet::getDirections(size_t idx) const
{
	return m_directions[idx];
}

inline double VelocitySet::get_c_square(size_t idx) const
{
	return m_cSquare;
}

inline size_t VelocitySet::get_nDimensions() const
{
	return m_nDimensions;
}

inline size_t VelocitySet::get_nDirections() const
{
	return m_nDirections;
}