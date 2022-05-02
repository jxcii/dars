#include "Neuron.h"
class layer {
	_type type;
public:
	vector<Neuron*> neurons;
	layer(int size, _type type = normal) : type(type) {
		for (int c = 0; c < size; c++) neurons.push_back(new Neuron());
	}
	vector<double> FeedForward() {
		vector<double> inputs;
		for (int c = 0; c < neurons.size(); c++) inputs.push_back(neurons[c]->output);
		return inputs;
	}
};