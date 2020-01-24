#pragma once

#include <vector>
#include <iostream>
#include "VelocitySet.h"

class Node : public Domain
{
private:
	int m_x;
	int m_y;
	double m_velocity;
	std::vector<double> m_distributions;
	std::vector<double> m_newDistribution;

public:
	Node(int x, int y);
	~Node();

	double Equilibrium(const VelocitySet& velSet, size_t dir);
	double Distribution();
	double Density();
	std::vector<double> Velocity(const VelocitySet& velSet, size_t idx);
};

