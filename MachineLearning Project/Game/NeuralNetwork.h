#pragma once
#include"Neuron.h"

class NeuralNetwork
{
private:
	Neuron InputNeuron1;
	Neuron InputNeuron2;
	Neuron HiddenLayerNeuron;
	Neuron OutputNeuron;
public:
	void LoadProgress(const char* filename);
	void SaveProgress(const char* filename);
	void InputLayer(int birdY, int CheckPointY);
	void HiddenLayer();
	void ActivationFunction();
	void reLU(double x, double y);
	void OutputLayer();
	bool Output();
	void changeWeight1(int x);
	void changeWeight2(int x);
	void Update(int birdY, int CheckPointY);

};

