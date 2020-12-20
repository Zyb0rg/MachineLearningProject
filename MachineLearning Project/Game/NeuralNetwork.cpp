#include "NeuralNetwork.h"
#include <fstream>

void NeuralNetwork::LoadProgress(const char* filename)
{
	std::ifstream File(filename);
	File >> InputNeuron2.bias;
	File.close();
}

void NeuralNetwork::SaveProgress(const char* filename)
{
	std::ofstream File(filename);
	File << rand() % 500 - 250;
	File.close();
}

void NeuralNetwork::InputLayer(int birdY, int CheckPointY)
{
	InputNeuron1.value = birdY;
	InputNeuron2.value = CheckPointY;
}

void NeuralNetwork::HiddenLayer()
{
	// Attaching biases and weights to the neuron
	InputNeuron1.value = InputNeuron1.value + InputNeuron1.weight + InputNeuron1.bias;
	InputNeuron2.value = InputNeuron2.value + InputNeuron2.weight + InputNeuron2.bias;

	// reLU Activation Function
	ActivationFunction();
}

void NeuralNetwork::ActivationFunction()
{
	// Normalization on the scale 0 - 1 for reLU function
	double x = InputNeuron1.value / 600;	// ------> 600 being the height of the screen, maximum Y coordinate.
	double y = InputNeuron2.value / 600;

	// Rectified Linear Unit
	reLU(x, y);
}

void NeuralNetwork::Update(int birdY, int CheckPointY)
{
	// Flow of Program
	LoadProgress("Progress.txt");
	InputLayer(birdY, CheckPointY);
	HiddenLayer();
	OutputLayer();
}

void NeuralNetwork::OutputLayer()
{
	if (HiddenLayerNeuron.value > ((1 + HiddenLayerNeuron.weight) / 0.5))
	{
		OutputNeuron.value = 1;
	}
	else
	{
		OutputNeuron.value = 0;
	}
}

void NeuralNetwork::reLU(double x, double y)
{
	// Neglecting -ve values, reLU doesn't deal with neg values
	if (x < 0 || y < 0)
	{
		HiddenLayerNeuron.value = 0;
	}
	else
	{
		// Applying reLU function
		HiddenLayerNeuron.value = (x + y) / y;
	}
}

bool NeuralNetwork::Output()
{
	if (OutputNeuron.value == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


