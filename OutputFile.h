#pragma once

#include "Node.h"
#include <fstream>
#include <string>

class OutputFile
{
private:
	int m_outputIdx;

public:
	OutputFile(int outputIdx);
	~OutputFile();

	void WriteCSV(std::vector<std::shared_ptr<Node>> lattice, std::shared_ptr<VelocitySet> velSet);
};

