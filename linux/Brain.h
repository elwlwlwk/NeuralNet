#include "NeuralNet.h"

class CBrain{
private:
	vector<CNeuralNet> v_NeuralNet;
public:
	CBrain(int columns, int m_NumInputs, int m_NumOutputs, int m_NumHiddenLayers, int m_NeuronsPerHiddenLyr);
	void AddNet(CNeuralNet newNet);
	void train(int column, vector<v_double> trainingset, vector<v_double> targetset);
	int update(vector<double> input);

	void Save();
	void Load();
};