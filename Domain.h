#pragma once
#include "ZouHe.h"

class Domain
{
public:
	int m_nDimensions = m_domainSize.size();
private:
	std::shared_ptr<VelocitySet> m_velSet;
	std::vector<std::shared_ptr<Node>> m_lattice;
	std::vector<int> m_domainSize;
	int m_cylinderX0, m_cylinderY0, m_radius;
public:
	Domain(std::shared_ptr<VelocitySet> velSet, const std::vector<int> domainSize, int cylinderX0, int cylinderY0, int radius);
	~Domain();

	void CreateNodes();
	bool IsInDomain(int coord_x, int coord_y);
	double Distance(int x, int y);
	const std::shared_ptr<VelocitySet> GetVelSet();
	void ConnectNodes();
	void Initialize();

	friend class Simulation;
	friend class Node;
};

