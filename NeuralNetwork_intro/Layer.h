#pragma once
#include <vector>

#include "Neuron.h"

class Layer
{
public:
	Layer() {}
	~Layer() {}

	void printLayer() const {}

public:

	std::vector<Neuron> listOfNeurons;
	size_t numberOfNeuronInLayer;
};
