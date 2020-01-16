#pragma once
#include <vector>

using namespace std;

class VelocitySet
{
private:
	vector<double> const m_weights;
	vector<vector<int>> const m_directions;
	size_t m_nDirections;
	size_t m_nDimensions;
	double const m_cSquare;

public:
	VelocitySet(vector<double> weights, vector<vector<int>> directions, double cSquare);
	~VelocitySet();

	double getWeights(size_t idx) const;
	vector<int> getDirections(size_t idx) const;
	double get_c_square(size_t idx) const;
	size_t get_nDimensions() const;
	size_t get_nDirections() const;
};

