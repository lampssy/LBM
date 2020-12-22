#pragma once

#include <vector>

class VelocitySet
{
private:
	std::vector<double> const m_weights;
	std::vector<std::vector<int>> const m_directions;
	double const m_cSquare;
	int m_nrOfDimensions;

public:
	VelocitySet(std::vector<double> weights, std::vector<std::vector<int>> directions, double cSquare);
	~VelocitySet();

	double GetWeight(int dir) const;
	std::vector<int> GetDirection(int dir) const;
	double Get_c_square(int dir) const;
	int Get_nDimensions() const;
	int Get_nDirections() const;
	virtual int OppositeDirection(int dir) const;
};

