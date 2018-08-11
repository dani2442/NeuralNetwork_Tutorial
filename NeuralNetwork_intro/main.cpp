#include "InputLayer.h"
#include "OutputLayer.h"
int main() {
	InputLayer inputL;
	inputL.numberOfNeuronInLayer = 5;
	inputL=inputL.initLayer(inputL);
	inputL.printLayer(inputL);

	OutputLayer outputL;
	outputL.numberOfNeuronInLayer = 2;
	outputL = outputL.initLayer(outputL);
	outputL.printLayer(outputL);



	getchar();
}