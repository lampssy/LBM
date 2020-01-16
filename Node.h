#pragma once

#include <vector>
#include <iostream>

class Node
{
private:
	std::vector<double> m_distributions;
	std::vector<double> m_newDistribution;
	//std::vector<int> m_neighbours;
	double* m_neighbour;
	// int m_position[2];
	int* m_position;

public:
	Node();
	~Node();

	double calculateDistribution();
	double calculateDensity();
	double calculateVelocity();
};

