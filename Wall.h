#pragma once

#include "InternalNode.h"
#include "Domain.h"

class Wall	:	public InternalNode
{
private:
	int m_coordX, m_coordY;	// wall node should know its position to decide if apply bounceback 
public:
	Wall(int x, int y);
	~Wall();

	void Stream(const VelocitySet& velSet, Node* neighbour, size_t dir, Domain domain) override;
	bool IsBounceBack(const VelocitySet& velSet, size_t dir, const Domain& domain);
};

