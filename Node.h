#pragma once

#include "VelocitySet.h"

class Node
{
public:
	std::vector<double> m_distributions;
	std::vector<double> m_newDistributions;
public:
	Node();
	~Node();

	double Equilibrium(const VelocitySet& velSet, size_t dir);
	double Density();
	std::vector<double> Velocity(const VelocitySet& velSet, size_t idx);
	virtual void Stream(const VelocitySet& velSet, Node* neighbour, size_t dir, Domain domain) = 0;	// every node type has to have streaming implemented
};

