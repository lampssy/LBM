#include "InternalNode.h"
#include "Domain.h"


InternalNode::InternalNode()
{
}


InternalNode::~InternalNode()
{
}


void InternalNode::Stream(const VelocitySet& velSet, Node* neighbour, size_t dir, Domain domain)
{
	neighbour->m_distributions[dir] = this->m_newDistributions[dir];
}