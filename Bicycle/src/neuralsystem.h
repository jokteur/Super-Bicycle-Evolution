#ifndef NEURALSYSTEM_H
#define NEURALSYSTEM_H

#include <cstdint>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>

#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

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
    vector<MatrixXf> _layers;
	vector<MatrixXf> _signal;
    vector<MatrixXf> _weights;


	MatrixXf binaryThreshold(MatrixXf value);
	void sigmoid(MatrixXf & in);

    float rectifiedLinear(float value);

public:
	NeuralSystem(MatrixXf inputs, MatrixXf outputs, MatrixXf weights, Fonction outputFct);
	NeuralSystem(MatrixXf inputs, MatrixXf outputs, Fonction outputFct);


	void addLayer(MatrixXf layer, MatrixXf weights, Fonction fct);
	void addLayer(MatrixXf layer, Fonction fct);

    vector<MatrixXf> makeDecision(const MatrixXf& input);
    void displayNetwork();

};

#endif // NEURALSYSTEM_H
