#pragma once

#include "VelocitySet.h"
#include "Node.h"

class Domain
{
public:
	size_t m_nDimensions = m_domainSize.size();
private:
	VelocitySet m_velSet;
	vector<vector<Node>> m_nodes;
	vector<size_t> m_domainSize;
public:
	Domain(const VelocitySet& velSet, const vector<size_t>& domainSize);
	~Domain();

	void CreateNodes();
	Node InitializeNode(std::vector<double> coordinates);
};

