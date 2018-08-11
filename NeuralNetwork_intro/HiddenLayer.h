#pragma once
#include "Layer.h"
#include "InputLayer.h"
#include "OutputLayer.h"

class HiddenLayer: public Layer
{
public:
	HiddenLayer(){}
	~HiddenLayer(){}

	std::vector<HiddenLayer>& initLayer(const HiddenLayer&, std::vector<HiddenLayer>&, const InputLayer&, const OutputLayer&);
	void printLayer(const std::vector<HiddenLayer>& listOfHiddenLayer) const;

private:

};

inline std::vector<HiddenLayer>& HiddenLayer::initLayer(
	const HiddenLayer&				hiddenLayer,
	std::vector<HiddenLayer>&		listOfHiddenLayer, 
	const InputLayer&				inputLayer, 
	const OutputLayer&				outputLayer) 
{
	std::vector<double> listOfWeightIn;
	std::vector<double> listOfWeightOut;
	std::vector<Neuron> listOfNeurons;

	size_t numberOfHiddenLayers = listOfHiddenLayer.size();

	for (size_t i = 0; i < numberOfHiddenLayers; i++) {
		for (size_t j = 0; j < hiddenLayer.numberOfNeuronInLayer; j++) {
			Neuron neuron;

			size_t limitIn;
			size_t limitOut;

			if (i == 0) {
				limitIn = inputLayer.numberOfNeuronInLayer;
				if (numberOfHiddenLayers > 1)
					limitOut = listOfHiddenLayer[i + 1].numberOfNeuronInLayer;
				else if (numberOfHiddenLayers == 1)
					limitOut = outputLayer.numberOfNeuronInLayer;
			}
			else if (i == numberOfHiddenLayers - 1) {
				limitIn = listOfHiddenLayer[i - 1].numberOfNeuronInLayer;
				limitOut = outputLayer.numberOfNeuronInLayer;
			}
			else {
				limitIn = listOfHiddenLayer[i - 1].numberOfNeuronInLayer;
				limitOut = listOfHiddenLayer[i + 1].numberOfNeuronInLayer;
			}
			limitIn--; // Bias in not connected
			limitOut--; // Bias is not connected

			if (j >= 1) {
				for (size_t k = 0; k <= limitIn; k++) {
					listOfWeightIn.push_back(neuron.initNeuron);
				}
			}
			for (size_t k = 0; k <= limitOut; k++) {
				listOfWeightOut.push_back(neuron.initNeuron());
			}

			neuron.listOfWeightIn = listOfWeightIn;
			neuron.listOfWeightOut = listOfWeightOut;
			listOfNeurons.push_back(neuron);

			listOfWeightIn.clear();
			listOfWeightOut.clear();
		}
		listOfHiddenLayer[i].listOfNeurons = listOfNeurons;
		this->listOfNeurons = listOfNeurons;
		listOfNeurons.clear();
	}
	return listOfHiddenLayer;
}

inline void HiddenLayer::printLayer(const std::vector<HiddenLayer>& listOfHiddenLayer) const
{
	std::cout << "### HIDDEN LAYER ###" << std::endl;
	int h = 1;
	for (HiddenLayer hiddenLayer : listOfHiddenLayer) {
		std::cout << "Hidden Layer #" << h << std::endl;
		int n = 1;
		for (Neuron& neuron : hiddenLayer.listOfNeurons) {
			std::cout << "Neuron #" << n << std::endl;
			std::cout << "Input Weights:" << std::endl;
			std::vector<double> weights = neuron.listOfWeightIn;
			for (double weight : weights)
				std::cout << weight << " ";
			std::cout << std::endl << "Output Weights:" << std::endl;
			weights = neuron.listOfWeightOut;
			for (double weight : weights)
				std::cout << weight << " ";
			std::cout << std::endl;
			n++;
		}
		h++;
	}
}
