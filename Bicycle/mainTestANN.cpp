/*******************************************************
 * Copyright (c) 2014, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#include <arrayfire.h>
#include <cstdio>
#include <iostream>
#include <math.h>

#include "src/neuralsystem.h"
#include "matrix.h"

using namespace af;

int main(int argc, char *argv[])
{
	int height = 15;
	Matrix input = randUniform(-1, 1, height);
	Matrix output = randUniform(-1, 1, height);
	NeuralSystem brain(input, output, SIGMOID);
	brain.addLayer(randUniform(-1, 1, height), SIGMOID);
	brain.addLayer(randUniform(-1, 1, height), SIGMOID);
	brain.addLayer(randUniform(-1, 1, height), SIGMOID);

	Matrix ar1 = randUniform(-1, 1, height);

	timer::start();
	for (int i = 0; i < 100000; i++)
	{
		brain.makeDecision(ar1);
	}

	std::cout << "#Decisions par seconde : " << 100000/timer::stop() << std::endl;
	string str = "";
	cin >> str;
    return 0;
}

//#include <iostream>

//#include "neuralsystem.h"

//using namespace std;

//int main(int argc, char *argv[])
//{
//    cout << "Hello World!" << endl;

//    NeuralSystem brain(5,4,1,1);
//    brain.addLayer(6,1.5,1);
//    brain.addLayer(4,3.5,1);
//    brain.addLayer(10,2.84,1);

//    brain.displayNetwork();
//    //brain.makeDecision(3);

//    return 0;
//}
