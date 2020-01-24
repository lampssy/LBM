#pragma once
#include <vector>

using namespace std;

class VelocitySet
{
private:
	vector<double> const m_weights;
	vector<vector<int>> const m_directions;
	double const m_cSquare;
	size_t m_nrOfDimensions;

public:
	VelocitySet(vector<double> weights, vector<vector<int>> directions, double cSquare);
	~VelocitySet();

	double getWeight(size_t dir) const;
	vector<int> getDirection(size_t dir) const;
	double get_c_square(size_t dir) const;
	size_t get_nDimensions() const;
	size_t get_nDirections() const;
};

