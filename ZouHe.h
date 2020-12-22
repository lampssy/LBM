#pragma once
#include "Node.h"

class ZouHe :
	public Node
{
private:
	std::vector<double> m_inletVel;
public:
	static const double PI;
public:
	ZouHe(int coord_x, int coord_y);
	~ZouHe();

	//double Density() override;
	void ApplyBC() override;
	void SetInletVel(double ux, double uy);
	bool IsCorner();
	bool IsCornerLow();
	bool IsCornerTop();
	double Density() override;
	virtual std::vector<double> Velocity(std::shared_ptr<VelocitySet> velSet) override;
};

