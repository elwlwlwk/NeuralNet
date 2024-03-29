#ifndef __NEURALNET_H__
#define __NEURALNET_H__

#include <vector>
#include "NeuralLib.h"

using namespace std;

typedef vector<double> v_double;

struct SNeuron{
	int m_NumInputs;
	vector<double> m_vecWeight;

	double m_dActivation;

	double m_dError;

	SNeuron(int NumInputs);
};

struct SNeuronLayer{
	int m_NumNeurons;

	vector<SNeuron> m_vecNeurons;

	SNeuronLayer(int NumNeurons, int NumInputsPerNeuron);
};

class CNeuralNet{
private:
	int m_NumInputs;
	int m_NumOutputs;
	int m_NumHiddenLayers;
	int m_NeuronsPerHiddenLyr;

	vector<SNeuronLayer> m_vecLayers;

	double m_dErrorSum;

public:
	CNeuralNet();
	CNeuralNet(int m_NumInputs, int m_NumOutputs, int m_NumHiddenLayers, int m_NeuronsPerHiddenLyr);
	CNeuralNet(char* src);
	void CreateNet();
	vector<double> GetWeights() const;
	int GetNumberOfWeights() const;
	void LoadWeights(char* src);
	void SaveWeights(char* src);


	vector<double> Update(vector<double> inputs);

	void Backpropagation(vector<v_double> InputSet, vector<v_double> ObjectSet);

	void Training(vector<v_double> traningset, vector<v_double> outputset);

};

#endif