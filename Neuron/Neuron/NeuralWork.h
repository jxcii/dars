#include "layer.h"
class NeuralWork {
	vector<layer> layers;
public:
	NeuralWork(vector<int> topology)
	{
		layers.push_back(layer(topology[0], input));
		for (int c = 0; c < layers[0].neurons.size(); c++) layers[0].neurons[c] = new Neuron(1, input);
		for (int c = 1; c < topology.size() - 1; c++) {
			layers.push_back(layer(topology[c]));
			for (int j = 0; j < layers[c].neurons.size(); j++)
				layers[c].neurons[j] = new Neuron(topology[c - 1]);
		}
		layers.push_back(layer(topology[topology.size() - 1], output));
		for (int c = 0; c < layers[layers.size() - 1].neurons.size(); c++)
			layers[layers.size() - 1].neurons[c] = new Neuron(layers[layers.size() - 2].neurons.size(), output);
	}
	vector<double> FeedForward(vector<double> localinputs) {
		for (int c = 0; c < layers[0].neurons.size(); c++) layers[0].neurons[c]->FeedForward({ localinputs[c] });
		for (int c = 1; c < layers.size(); c++) {
			localinputs = layers[c - 1].FeedForward();
			for (int j = 0; j < layers[c].neurons.size(); j++) layers[c].neurons[j]->FeedForward(localinputs);
		}
		vector<double> result;
		for (int c = 0; c < layers[layers.size() - 1].neurons.size(); c++) result.push_back(layers[layers.size() - 1].neurons[c]->output);
		return result;
	}
};