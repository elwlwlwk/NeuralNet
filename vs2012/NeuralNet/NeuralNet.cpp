#include "NeuralNet.h"

#ifdef _WIN32
#include <Windows.h>
#endif

SNeuron::SNeuron(int NumInputs):m_NumInputs(NumInputs+1){
	for(int i=0; i< m_NumInputs; i++){
		m_vecWeight.push_back(RandomClamped());
#ifdef _WIN32
		//Sleep(1);
#endif
	}
}

SNeuronLayer::SNeuronLayer(int NumNeuron, int NumInputsPerNeuron):m_NumNeurons(NumNeuron){
	for(int i=0; i<NumNeuron; i++){
		m_vecNeurons.push_back(SNeuron(NumInputsPerNeuron));
	}
}

CNeuralNet::CNeuralNet(){
	CreateNet();
}

CNeuralNet::CNeuralNet(int m_NumInputs, int m_NumOutputs, int m_NumHiddenLayers, int m_NeuronsPerHiddenLyr){
	this->m_NeuronsPerHiddenLyr= m_NeuronsPerHiddenLyr;
	this->m_NumHiddenLayers= m_NumHiddenLayers;
	this->m_NumInputs= m_NumInputs;
	this->m_NumOutputs= m_NumOutputs;
	m_dErrorSum= 1000;
	CreateNet();
}


void CNeuralNet::CreateNet(){
	int t= time(NULL);
	srand(t);
	//create inputlayer
	m_vecLayers.push_back(SNeuronLayer(m_NeuronsPerHiddenLyr, m_NumInputs));
	if(m_NumHiddenLayers> 0){
		//create hiddenlayer
		for(int i=0; i<m_NumHiddenLayers; i++){
			m_vecLayers.push_back(SNeuronLayer(m_NeuronsPerHiddenLyr, m_NeuronsPerHiddenLyr));
		}
	}
	//create outputlayer
	m_vecLayers.push_back(SNeuronLayer(m_NumOutputs, m_NeuronsPerHiddenLyr));
}

//vector<double> CNeuralNet::GetWeights() const{
//}

int CNeuralNet::GetNumberOfWeights() const{
	return m_NumInputs;
}

vector<double> CNeuralNet::Update(vector<double> inputs){
	vector<double> outputs;

	for(int i=0; i< m_NumHiddenLayers+2; i++){
		if(i!= 0){
			inputs= outputs;
			outputs.clear();
		}
		for(int j=0; j< m_vecLayers[i].m_NumNeurons; j++){
			double netinput= 0;
			for(int k=0; k< m_vecLayers[i].m_vecNeurons[j].m_NumInputs-1; k++){
				netinput+= m_vecLayers[i].m_vecNeurons[j].m_vecWeight[k]* inputs[k];
			}
			netinput+= m_vecLayers[i].m_vecNeurons[j].m_vecWeight[m_vecLayers[i].m_vecNeurons[j].m_NumInputs-1]* M_BIAS;
			m_vecLayers[i].m_vecNeurons[j].m_dActivation= Sigmoid(netinput, M_SIGRESP);
			outputs.push_back(m_vecLayers[i].m_vecNeurons[j].m_dActivation);
		}
	}

	return outputs;
}

void CNeuralNet::Backpropagation(vector<vector<double>> InputSet, vector<vector<double>> ObjectSet){
}