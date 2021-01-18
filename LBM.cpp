// LBM-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "D2Q9.h"
#include "Simulation.h"
#include "OutputFile.h"

int main()
{
	int dx = 300;
	int dy = 150;
	int x_cylinder = dx / 4;
	int y_cylinder = dy / 2;
	int r = dy / 12;
	double vel_LB = 0.04;
	double Re = 220;
	double nu_LB = 2 * vel_LB * r / Re;
	double tau = 3 * nu_LB + 0.5;

	std::vector<int> domainSize{ dx, dy };
	std::shared_ptr<D2Q9> velSet = std::make_shared<D2Q9>();
	Domain domain(velSet, domainSize, x_cylinder, y_cylinder, r);
	domain.CreateNodes();
	domain.ConnectNodes();
	domain.Initialize();

	Simulation sim(domain);
	sim.SetRelaxation(tau);

	int max_iter = 0;
	//std::cout << "Enter the number of iterations: " << std::endl;
	//std::cin >> max_iter;
	max_iter = 10000;

	for (int iter = 1; iter <= max_iter; iter++)
	{
		sim.Iterate();
		std::cout << "Iteration: " << iter << std::endl;

		if (iter % 1000 == 0)
			sim.WriteOutput(iter);
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
