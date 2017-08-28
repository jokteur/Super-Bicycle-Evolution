#include "neuralsystem.h"

Matrix NeuralSystem::binaryThreshold(Matrix value)
{
	return 0.0f;
}

void NeuralSystem::sigmoid(Matrix &in)
{
	in = in;
}


NeuralSystem::NeuralSystem(Matrix inputs, Matrix outputs, Matrix weights, Fonction outputFct)
{
	_layers.push_back(inputs);
	_signal.push_back(inputs);

	_layers.push_back(outputs);
	_signal.push_back(outputs);

	_weights.push_back(weights);

	_layersFctType.push_back(outputFct);
	_numLayers = 2;
}

NeuralSystem::NeuralSystem(Matrix inputs, Matrix outputs, Fonction outputFct)
{
	_layers.push_back(inputs);
	_signal.push_back(inputs);

	_layers.push_back(outputs);
	_signal.push_back(outputs);

	Matrix weights = randUniform(-1, 1, outputs.size(), inputs.size());
	_weights.push_back(weights);

	_layersFctType.push_back(outputFct);

	_numLayers = 2;
}

void NeuralSystem::addLayer(Matrix layer, Fonction fct)
{
	Matrix output = _layers.back();
	Fonction outputFct = _layersFctType.back();
	Matrix signalOutput = _signal.back();

	_layers.pop_back();
	_signal.pop_back();
	_weights.pop_back();

	_weights.push_back(randUniform(-1, 1, layer.size(), _layers.back().size()));
	_weights.push_back(randUniform(-1, 1, output.size(), layer.size()));
	_layers.push_back(layer);
	_signal.push_back(layer);
	_layers.push_back(output);
	_signal.push_back(output);

	_layersFctType.push_back(fct);
	_layersFctType.push_back(outputFct);
	_numLayers++;
}

vector<Matrix> NeuralSystem::makeDecision(const Matrix& input)
{
	_signal[0] = input;
	int j = 0;
	for (int i = 0; i < _numLayers - 1; i++)
	{
		j = i + 1;
		switch (_layersFctType[i])
		{
		case SIGMOID:
			_signal[j] = mult(_weights[i], _layers[i]) + _layers[j];
		}
	}
	return _signal;
}
