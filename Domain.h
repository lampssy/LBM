#pragma once

#include "VelocitySet.h"
#include "Node.h"

class Domain
{
private:
	VelocitySet m_velSet;
	vector<size_t> m_domainSize;
	vector<Node> m_nodes;
public:
	Domain(const VelocitySet& velSet, vector<size_t> domainSize);
	~Domain();

	void CreateNodes();
	Node InitializeNode(std::vector<double> position);
};

