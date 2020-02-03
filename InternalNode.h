#pragma once

#include "Node.h"

class InternalNode	:	public Node
{
public:
	InternalNode();
	~InternalNode();

	void Stream(const VelocitySet& velSet, Node* neighbour, size_t dir, Domain domain) override;
};

