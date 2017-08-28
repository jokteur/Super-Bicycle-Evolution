#include "neuralsystem.h"

af::array NeuralSystem::binaryThreshold(af::array value)
{
	return 0.0f;
}

void NeuralSystem::sigmoid(af::array &in)
{
	in = 1/(1+exp(in));
}

af::array my_mult(const af::array &lhs, const af::array &rhs)
{
	return lhs * rhs;
}

NeuralSystem::NeuralSystem(af::array inputs, af::array outputs, af::array weights, Fonction outputFct)
{
	_layers.push_back(inputs);
	_signal.push_back(inputs);

	_layers.push_back(outputs);
	_signal.push_back(outputs);

	_weights.push_back(weights);

	_layersFctType.push_back(outputFct);
	_numLayers = 2;
}

NeuralSystem::NeuralSystem(af::array inputs, af::array outputs, Fonction outputFct)
{
	_layers.push_back(inputs);
	_signal.push_back(inputs);

	_layers.push_back(outputs);
	_signal.push_back(outputs);

	af::array weights = randu(outputs.elements(), inputs.elements());
	_weights.push_back(weights);

	_layersFctType.push_back(outputFct);

	_numLayers = 2;
}

void NeuralSystem::addLayer(af::array layer, Fonction fct)
{
	af::array output = _layers.back();
	Fonction outputFct = _layersFctType.back();
	af::array signalOutput = _signal.back();

	_layers.pop_back();
	_signal.pop_back();
	_weights.pop_back();

	_weights.push_back(randu(layer.elements(), _layers.back().elements()));
	_weights.push_back(randu(output.elements(), layer.elements()));
	_layers.push_back(layer);
	_signal.push_back(layer);
	_layers.push_back(output);
	_signal.push_back(output);

	_layersFctType.push_back(fct);
	_layersFctType.push_back(outputFct);
	_numLayers++;
}

vector<af::array> NeuralSystem::makeDecision(const af::array& input)
{
	_signal[0] = input;
	int j = 0;
	for (int i = 0; i < _numLayers - 1; i++)
	{
		j = i + 1;
		switch (_layersFctType[i])
		{
		case SIGMOID:
			_signal[j] = tanh(matmul(_weights[i], _layers[i]) + _layers[j]);
		}
	}
	return _signal;
}
