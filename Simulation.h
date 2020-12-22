#pragma once

#include "VelocitySet.h"
#include "Domain.h"
#include "OutputFile.h"

class Simulation
{
private:
	Domain m_domain;
	double m_relaxation;
private:
	void Collision();
	void Streaming();
	void InletBC();
	void OutletBC();

public:
	Simulation(Domain& domain);
	~Simulation();

	void Iterate();
	void SetRelaxation(double tau);
	void WriteOutput(int iter);
};

