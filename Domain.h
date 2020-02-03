#pragma once

#include "Node.h"
#include "InternalNode.h"
#include "Wall.h"

class Domain
{
public:
	size_t m_nDimensions = m_domainSize.size();
private:
	VelocitySet m_velSet;
	std::vector<std::vector<Node>> m_lattice;
	std::vector<size_t> m_domainSize;
	int m_cylinderX0, m_cylinderY0, m_radius;
public:
	Domain(const VelocitySet& velSet, const std::vector<size_t>& domainSize, int cylinderX0, int cylinderY0, int radius);
	~Domain();

	void CreateNodes();
	bool IsInDomain(int coord_x, int coord_y) const;
	double Distance(int x, int y);
	//void InitializeNodes();

	friend class Node;
};

