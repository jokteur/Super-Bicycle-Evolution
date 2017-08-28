#ifndef NEURALSYSTEM_H
#define NEURALSYSTEM_H

#include <cstdint>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>

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

class ANN
{
private:
	uint8_t _numLayers;
    vector<Fonction> _layersFctType;
    vector<MatrixXf> _layers;
	vector<MatrixXf> _signal;
    vector<MatrixXf> _weights;

	//Number generation
	std::default_random_engine _generator;
	std::normal_distribution<float> *_distribution;
public:
	ANN(MatrixXf inputs, MatrixXf outputs, MatrixXf weights, Fonction outputFct);
	ANN(MatrixXf inputs, MatrixXf outputs, Fonction outputFct);

	void addLayer(MatrixXf layer, Fonction fct);

    vector<MatrixXf> makeDecision(const MatrixXf& input);
    void displayNetwork();

	void mutate(float sigma);

	float Gaussian(float x);
};

ANN reproduceANN(const ANN &ANN1, const ANN &ANN2);

#endif // NEURALSYSTEM_H
