/*******************************************************
 * Copyright (c) 2014, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#define EIGEN_USE_BLAS

#include <cstdio>
#include <iostream>
#include <math.h>
#include <ctime>
#include <Eigen/Dense>

#include "src/ANN.h"

using namespace Eigen;

int main(int argc, char *argv[])
{
	setNbThreads(0);

	int height = 15;
	MatrixXf input = MatrixXf::Random(height, 1);
	MatrixXf output = MatrixXf::Random(height, 1);
	ANN brain(input, output, SIGMOID);
	brain.addLayer(MatrixXf::Random(height, 1), SIGMOID);
	brain.addLayer(MatrixXf::Random(height, 1), SIGMOID);
	brain.addLayer(MatrixXf::Random(height, 1), SIGMOID);

	MatrixXf ar1 = MatrixXf::Random(height, 1);
	
	std::clock_t start;
	double duration;

	start = std::clock();

	brain.displayNetwork();

	for (int i = 0; i < 10000; i++)
	{
		brain.mutate(1.0f);
	}
	std::cout << std::endl;
	brain.displayNetwork();

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "#Mutations par seconde : " << 100000/duration << " Nbr of threads : " << Eigen::nbThreads() << std::endl;
	string str = "";
	cin >> str;
    return 0;
}
