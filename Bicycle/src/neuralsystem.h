#ifndef NEURALSYSTEM_H
#define NEURALSYSTEM_H

#include <cstdint>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>

#include <arrayfire.h>

#include "../matrix.h"

using namespace af;
using namespace std;

enum Fonction
{
	BINARY_THRESHOLD,
	RECTIFIED_LINEAR,
	SIGMOID,
	SOFTMAX
};

class NeuralSystem
{
private:
	uint8_t _numLayers;
    vector<Fonction> _layersFctType;
    vector<Matrix> _layers;
	vector<Matrix> _signal;
    vector<Matrix> _weights;


	Matrix binaryThreshold(Matrix value);
	void sigmoid(Matrix & in);

    float rectifiedLinear(float value);

public:
	NeuralSystem(Matrix inputs, Matrix outputs, Matrix weights, Fonction outputFct);
	NeuralSystem(Matrix inputs, Matrix outputs, Fonction outputFct);


	void addLayer(Matrix layer, Matrix weights, Fonction fct);
	void addLayer(Matrix layer, Fonction fct);

    vector<Matrix> makeDecision(const Matrix& input);
    void displayNetwork();

};

#endif // NEURALSYSTEM_H
