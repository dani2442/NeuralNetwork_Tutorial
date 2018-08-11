#pragma once
#include <iostream>

#include "Layer.h"

class InputLayer: public Layer
{
public:
	InputLayer(){};
	~InputLayer(){};

	InputLayer& initLayer(InputLayer& inputLayer);
	void printLayer(InputLayer& inputLayer);

private:

};

inline InputLayer& InputLayer::initLayer(InputLayer& inputLayer) {
	std::vector<double> listOfWeightInTemp;
	std::vector<Neuron> listOfNeurons;

	for (size_t i = 0; i < inputLayer.numberOfNeuronInLayer; i++) {
		Neuron neuron;
		listOfWeightInTemp.push_back(neuron.initNeuron());

		neuron.listOfWeightIn=listOfWeightInTemp;
		listOfNeurons.push_back(neuron);
		
		listOfWeightInTemp.clear();
	}

	inputLayer.listOfNeurons=listOfNeurons;
	return inputLayer;
}

inline void InputLayer::printLayer(InputLayer & inputLayer)
{
	std::cout << "### INPUT LAYER ###" << std::endl;
	int n = 1;
	for (Neuron& neuron : inputLayer.listOfNeurons) {
		std::cout << "Neuron #" << n << ":" << std::endl;
		std::cout << "Input Weights:" << std::endl;
		std::vector<double> weights = neuron.listOfWeightIn;
		for (double weight : weights) {
			std::cout << weight << std::endl;
		}
		n++;
	}
}
