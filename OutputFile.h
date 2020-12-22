#pragma once

#include "Node.h"
#include <fstream>
#include <string>

class OutputFile
{
private:
	std::wstring m_outputIdx;

public:
	OutputFile(std::wstring outputIdx);
	~OutputFile();

	void CreateOutputDir();
	void WriteCSV(std::vector<std::shared_ptr<Node>> lattice, std::shared_ptr<VelocitySet> velSet);
};

