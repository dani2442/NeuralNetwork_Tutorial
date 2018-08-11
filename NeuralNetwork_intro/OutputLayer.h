#pragma once
#include <iostream>

#include "Layer.h"

class OutputLayer: public Layer
{
public:
	OutputLayer(){};
	~OutputLayer(){};

	OutputLayer& initLayer(OutputLayer& OutputLayer);
	void printLayer(OutputLayer& OutputLayer);

private:

};

inline OutputLayer& OutputLayer::initLayer(OutputLayer& OutputLayer) {
	std::vector<double> listOfWeightOutTemp;
	std::vector<Neuron> listOfNeurons;

	for (size_t i = 0; i < OutputLayer.numberOfNeuronInLayer; i++) {
		Neuron neuron;
		listOfWeightOutTemp.push_back(neuron.initNeuron());

		neuron.listOfWeightOut=listOfWeightOutTemp;
		listOfNeurons.push_back(neuron);
		
		listOfWeightOutTemp.clear();
	}

	OutputLayer.listOfNeurons=listOfNeurons;
	return OutputLayer;
}

inline void OutputLayer::printLayer(OutputLayer & OutputLayer)
{
	std::cout << "### OUTPUT LAYER ###" << std::endl;
	int n = 1;
	for (Neuron& neuron : OutputLayer.listOfNeurons) {
		std::cout << "Neuron #" << n << ":" << std::endl;
		std::cout << "Input Weights:" << std::endl;
		std::vector<double> weights = neuron.listOfWeightOut;
		for (double weight : weights) {
			std::cout << weight << std::endl;
		}
		n++;
	}
}
