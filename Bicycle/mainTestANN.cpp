/*******************************************************
 * Copyright (c) 2014, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#include <cstdio>
#include <iostream>
#include <math.h>
#include <ctime>
#include <Eigen/Dense>

#include "src/neuralsystem.h"

using namespace Eigen;

int main(int argc, char *argv[])
{
	int height = 15;
	MatrixXf input = MatrixXf::Random(height, 1);
	MatrixXf output = MatrixXf::Random(height, 1);
	NeuralSystem brain(input, output, SIGMOID);
	brain.addLayer(MatrixXf::Random(height, 1), SIGMOID);
	brain.addLayer(MatrixXf::Random(height, 1), SIGMOID);
	brain.addLayer(MatrixXf::Random(height, 1), SIGMOID);

	MatrixXf ar1 = MatrixXf::Random(height, 1);

	std::clock_t start;
	double duration;

	start = std::clock();
	for (int i = 0; i < 100000; i++)
	{
		brain.makeDecision(ar1);
	}
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "#Decisions par seconde : " << 100000/duration << std::endl;
	string str = "";
	cin >> str;
    return 0;
}
