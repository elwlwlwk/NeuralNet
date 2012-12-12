#include <vector>
#include "NeuralLib.h"

using namespace std;

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
	void CreateNet();
	vector<double> GetWeights() const;
	int GetNumberOfWeights() const;
	void PutWeights(vector<double> weigths);

	vector<double> Update(vector<double> inputs);

	void Backpropagation(vector<vector<double>> InputSet, vector<vector<double>> ObjectSet);

	void Training(vector<vector<double>> traningset, vector<vector<double>> outputset);

};