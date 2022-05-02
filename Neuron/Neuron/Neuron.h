#include <iostream>
#include <random>
#include <cmath>
#include <vector>
using namespace std;
enum _type {
	input,
	normal,
	output
};
class Neuron {
public:
	Neuron() {};
	vector<double> weights;
	//vector<double> inputs;
	double output;
	_type type;
	Neuron(int size, _type type = normal) : type(type)
	{
		if (type != input) 
			for (int c = 0; c < size; c++) weights.push_back(double(rand() % 101) / 100);
		else for (int c = 0; c < size; c++) weights.push_back(1);
	}
	double FeedForward(vector<double> inputs) {
		double sum = 0;
		for (int c = 0; c < weights.size(); c++) sum += weights[c] * inputs[c];
		if (type != input) output = Activation(sum);
		else output = sum;
		return output;
	}
	double Activation(double x) {
		return 1.0 / (1.0 + exp(-x));
	}
};