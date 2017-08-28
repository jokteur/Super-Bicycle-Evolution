#include "neuralsystem.h"

void NeuralSystem::sigmoid(MatrixXf &in)
{
	in = in;
}

NeuralSystem::NeuralSystem(MatrixXf inputs, MatrixXf outputs, MatrixXf weights, Fonction outputFct)
{
	_layers.push_back(inputs);
	_signal.push_back(inputs);

	_layers.push_back(outputs);
	_signal.push_back(outputs);

	_weights.push_back(weights);

	_layersFctType.push_back(outputFct);
	_numLayers = 2;
}

NeuralSystem::NeuralSystem(MatrixXf inputs, MatrixXf outputs, Fonction outputFct)
{
	_layers.push_back(inputs);
	_signal.push_back(inputs);

	_layers.push_back(outputs);
	_signal.push_back(outputs);

	MatrixXf weights = MatrixXf::Random(outputs.size(), inputs.size());
	_weights.push_back(weights);

	_layersFctType.push_back(outputFct);

	_numLayers = 2;
}

void NeuralSystem::addLayer(MatrixXf layer, Fonction fct)
{
	MatrixXf output = _layers.back();
	Fonction outputFct = _layersFctType.back();
	MatrixXf signalOutput = _signal.back();

	_layers.pop_back();
	_signal.pop_back();
	_weights.pop_back();

	_weights.push_back(MatrixXf::Random(layer.size(), _layers.back().size()));
	_weights.push_back(MatrixXf::Random(output.size(), layer.size()));
	_layers.push_back(layer);
	_signal.push_back(layer);
	_layers.push_back(output);
	_signal.push_back(output);

	_layersFctType.push_back(fct);
	_layersFctType.push_back(outputFct);
	_numLayers++;
}

vector<MatrixXf> NeuralSystem::makeDecision(const MatrixXf& input)
{
	_signal[0] = input;
	int j = 0;
	for (int i = 0; i < _numLayers - 1; i++)
	{
		j = i + 1;
		switch (_layersFctType[i])
		{
		case SIGMOID:
			_signal[j] = _weights[i] * _layers[i] + _layers[j];
		}
	}
	return _signal;
}
