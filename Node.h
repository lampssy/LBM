#pragma once
#include <iostream>
#include "VelocitySet.h"

class Node
{
public:
	std::vector<double> m_distributions;
	std::vector<double> m_newDistributions;
	std::shared_ptr<Node> m_neighbours[9];
	int x_position;
	int y_position;
public:
	Node(int coord_x, int coord_y);
	~Node();

	double Equilibrium(std::shared_ptr<VelocitySet> velSet, int dir);
	virtual double Density();
	virtual std::vector<double> Velocity(std::shared_ptr<VelocitySet> velSet);
	void Stream(int dir);
	void BounceBack(int dir, int opp_dir);
	virtual void ApplyBC();
};

