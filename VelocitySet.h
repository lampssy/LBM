#pragma once

#include <vector>

class VelocitySet
{
private:
	std::vector<double> const m_weights;
	std::vector<std::vector<int>> const m_directions;
	double const m_cSquare;
	size_t m_nrOfDimensions;

public:
	VelocitySet(std::vector<double> weights, std::vector<std::vector<int>> directions, double cSquare);
	~VelocitySet();

	double getWeight(size_t dir) const;
	std::vector<int> getDirection(size_t dir) const;
	double get_c_square(size_t dir) const;
	size_t get_nDimensions() const;
	size_t get_nDirections() const;
	virtual size_t OppositeDirection(size_t dir) const;
};

