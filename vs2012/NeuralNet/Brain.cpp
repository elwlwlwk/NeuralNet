/*
#include "Brain.h"

CBrain::CBrain(int columns, int m_NumInputs, int m_NumOutputs, int m_NumHiddenLayers, int m_NeuronsPerHiddenLyr){
	for(int i=0; i<columns; i++){
		CNeuralNet Temp(m_NumInputs, m_NumOutputs, m_NumHiddenLayers, m_NeuronsPerHiddenLyr);
		v_NeuralNet.push_back(Temp);
	}
}

void CBrain::AddNet(CNeuralNet newNet){
	v_NeuralNet.push_back(newNet);
}

void CBrain::train(int column, vector<v_double> trainingset, vector<v_double> targetset){
	v_NeuralNet.at(column).Backpropagation(trainingset, targetset);
}

int CBrain::update(vector<double> input){
	int result;

	float max= 0;
	int column;

	for(int i=0; i<5; i++){
		if(max< v_NeuralNet.at(i).Update(input).at(0)){
			column= i;
			max= v_NeuralNet.at(i).Update(input).at(0);
		}
	}

	return column;
}

void CBrain::Save(){
	char Str[100];

	for(int i=0; i< 5; i++){
		memset(Str, 0, sizeof(Str));
		sprintf(Str, "Net%d.txt", i);
		v_NeuralNet.at(i).SaveWeights(Str);
	}
}

void CBrain::Load(){
}
*/