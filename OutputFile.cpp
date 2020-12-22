#include "OutputFile.h"



OutputFile::OutputFile(std::wstring outputIdx)
	:	m_outputIdx(outputIdx)
{
}


OutputFile::~OutputFile()
{
}


void OutputFile::WriteCSV(std::vector<std::shared_ptr<Node>> lattice, std::shared_ptr<VelocitySet> velSet)
{
	std::ofstream velocityCSV;
	velocityCSV.open("U.csv");
	velocityCSV << "coordX" << "," << "coordY" << "," << "coordZ" << "," << "U" << std::endl;

	/*std::ofstream distributionsCSV;
	distributionsCSV.open("f.csv");
	distributionsCSV << "coordX" << "," << "coordY" << "," << "coordZ";
	std::string f = "f";
	for (int dir = 0; dir < velSet->Get_nDirections; dir++)
		distributionsCSV << "," << f.append(std::to_string(dir));
	distributionsCSV << std::endl;*/

	for (auto node : lattice)
		if (node != nullptr)
		{
			double velMag = sqrt(node->Velocity(velSet)[0] * node->Velocity(velSet)[0] + node->Velocity(velSet)[1] * node->Velocity(velSet)[1]);
			velocityCSV << node->x_position << "," << node->y_position << "," << 0 << "," << velMag << std::endl;
		}
}

void OutputFile::CreateOutputDir()
{
	wchar_t const* dirName = m_outputIdx.c_str();
	_wmkdir(dirName);
}
