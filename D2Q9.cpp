#include "D2Q9.h"

D2Q9::D2Q9()
	: VelocitySet(
		{ 4.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0 , 1.0 / 9.0, 1.0 / 36.0, 1.0 / 36.0, 1.0 / 36.0, 1.0 / 36.0 },
		{ {0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1} },
		1.0 / 3.0
	)
{
}


D2Q9::~D2Q9()
{
}

int D2Q9::OppositeDirection(int dir) const
{
	switch (dir)
	{
	case 0:
		return 0;
	case 1:
		return 3;
	case 2:
		return 4;
	case 3:
		return 1;
	case 4:
		return 2;
	case 5:
		return 7;
	case 6:
		return 8;
	case 7:
		return 5;
	case 8:
		return 6;
	}
}