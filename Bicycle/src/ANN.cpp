#include "ANN.h"

ANN::ANN(MatrixXf inputs, MatrixXf outputs, MatrixXf weights, Fonction outputFct)
{
	_layers.push_back(inputs);
	_signal.push_back(inputs);

	_layers.push_back(outputs);
	_signal.push_back(outputs);

	_weights.push_back(weights);

	_layersFctType.push_back(outputFct);
	_numLayers = 2;
}

ANN::ANN(MatrixXf inputs, MatrixXf outputs, Fonction outputFct)
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

void ANN::addLayer(MatrixXf layer, Fonction fct)
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

vector<MatrixXf> ANN::makeDecision(const MatrixXf& input)
{
	_signal[0] = input;
	int j = 0;
	for (int i = 0; i < _numLayers - 1; i++)
	{
		j = i + 1;
		switch (_layersFctType[i])
		{
		case SIGMOID:
			_signal[j] = _weights[i]*_layers[i] + _layers[j];
			int i = 0;
		}
	}
	return _signal;
}

void ANN::displayNetwork()
{
	uint16_t maxHeight = 0;
	for (int i = 0; i < _numLayers; i++)
	{
		if (_layers[i].size() > maxHeight)
			maxHeight = _layers[i].size();
	}
	for (int i = 0; i < maxHeight; i++)
	{
		for (int j = 0; j < _numLayers; j++)
		{
			if (_layers[j].size() > i)
			{
				std::cout << std::setprecision(3) << (_layers[j])(i, 0) << "   ";
			}
		}
		std::cout << std::endl;
	}
}

// define a custom template unary functor
template<typename Object>
struct CwiseClampOp {
	CwiseClampOp(const Object& distr, const Object& generator) : _distr(distr), _generator(generator) {}
	const Object operator()(const float& x) const { return x<m_inf ? m_inf : (x>m_sup ? m_sup : x); }
	Object _distr, _generator;
};

void ANN::mutate(float sigma)
{
	_distribution = new std::normal_distribution<float>(1.3, sigma);

	for (int i = 0; i < _numLayers; i++)
	{
		_layers[i] = _layers[i].unaryExpr([&](float elem)
		{
			return elem * (*_distribution)(_generator);
		});
	}
	for (int i = 0; i < _numLayers - 1; i++)
	{
		_weights[i] = _weights[i].unaryExpr([&](float elem)
		{
			return elem * (*_distribution)(_generator);
		});
	}
}

float ANN::Gaussian(float x)
{
	return x*(*_distribution)(_generator);
}

ANN reproduceANN(const ANN & ANN1, const ANN & ANN2)
{
	return ANN1;
}
