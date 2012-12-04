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

vector<double> CNeuralNet::Update(vector<double> &inputs){
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
/*
bool CNeuralNet::Backpropagation(vector<vector<double>> &SetIn, vector<vector<double>> &SetOut){
	vector<double>::iterator curWeight;
	vector<SNeuron>::iterator curNrnOut, curNrnHid;

	m_dErrorSum= 0;

	for(int vec=0; vec<SetIn.size(); vec++){
		vector<double> outputs= Update(SetIn[vec]);

		if(outputs.size()== 0){
			return false;
		}

		for(int op=0; op<m_NumOutputs; op++){
			double err= (SetOut[vec][op]- outputs[op])* outputs[op]*(1- outputs[op]);

			m_dErrorSum+= (SetOut[vec][op]- outputs[op])* (SetOut[vec][op]- outputs[op]);

			m_vecLayers[1].m_vecNeurons[op].m_dError= err;

			curWeight= m_vecLayers[1].m_vecNeurons[op].m_vecWeight.begin();
			curNrnHid= m_vecLayers[0].m_vecNeurons.begin();

			while(curWeight!= m_vecLayers[1].m_vecNeurons[op].m_vecWeight.end()-1){
				*curWeight+= err*M_LEARNRATE* curNrnHid->m_dActivation;

				++curWeight; ++curNrnHid;
			}
			*curWeight+= err* M_LEARNRATE* M_BIAS;
		}

		curNrnHid= m_vecLayers[0].m_vecNeurons.begin();

		int n=0;

		while(curNrnHid!= m_vecLayers[0].m_vecNeurons.end()){
			double err=0;
			curNrnOut= m_vecLayers[1].m_vecNeurons.begin();

			while(curNrnOut!= m_vecLayers[1].m_vecNeurons.end()){
				err+= curNrnOut->m_dError* curNrnOut->m_vecWeight[n];
				curNrnOut++;
			}

			err*= curNrnHid->m_dActivation*(1-curNrnHid->m_dActivation);

			for(int w=0; w<m_NeuronsPerHiddenLyr; w++){
				curNrnHid->m_vecWeight[w]+= err* M_LEARNRATE* SetIn[vec][w];
			}
			curNrnHid->m_vecWeight[m_NeuronsPerHiddenLyr]+= err* M_LEARNRATE* M_BIAS;

			curNrnHid++;
			n++;
		}
	}
	return true;
}*/


void CNeuralNet::Backpropagation(vector<double> Input, vector<double> Object){

	m_dErrorSum= 1000;
	while(m_dErrorSum> M_ACERR){
		m_dErrorSum= 0;
		vector<double> Output= Update(Input);

		for(int i=0; i< m_NumOutputs; i++){
			m_vecLayers[m_NumHiddenLayers+1].m_vecNeurons[i].m_dError= (Object[i]-Output[i])* Output[i]*(1-Output[i]);
		}
		for(int i=0; i< m_NumOutputs; i++){
			for(int j=0; j< m_vecLayers[m_NumHiddenLayers].m_NumNeurons; j++){
				m_vecLayers[m_NumHiddenLayers+1].m_vecNeurons[i].m_vecWeight[j]+= m_vecLayers[m_NumHiddenLayers+1].m_vecNeurons[i].m_dError* M_LEARNRATE* m_vecLayers[m_NumHiddenLayers+1].m_vecNeurons[i].m_dActivation;
			}
		}

		for(int i=0; i< m_NumOutputs; i++){
			m_dErrorSum+= m_vecLayers[m_NumHiddenLayers+1].m_vecNeurons[i].m_dError> 0? m_vecLayers[m_NumHiddenLayers+1].m_vecNeurons[i].m_dError: (m_vecLayers[m_NumHiddenLayers+1].m_vecNeurons[i].m_dError* -1);
		}

		for(int i= m_NumHiddenLayers; i>= 0; i--){
			for(int j=0; j<m_vecLayers[i].m_NumNeurons; j++){
				double err= 0;
				for(int k=0; k< m_vecLayers[m_NumHiddenLayers+1].m_NumNeurons; k++){
					err+= m_vecLayers[i].m_vecNeurons[j].m_dActivation*(1- m_vecLayers[i].m_vecNeurons[j].m_dActivation)* m_vecLayers[m_NumHiddenLayers+1].m_vecNeurons[k].m_dError*m_vecLayers[i].m_vecNeurons[j].m_vecWeight[k];
				}
				m_vecLayers[i].m_vecNeurons[j].m_dError= err;

				for(int k=0; k<m_vecLayers[i].m_vecNeurons[j].m_vecWeight.size()-1; k++){
					m_vecLayers[i].m_vecNeurons[j].m_vecWeight[k]+= m_vecLayers[i].m_vecNeurons[j].m_dActivation* M_LEARNRATE* m_vecLayers[i].m_vecNeurons[j].m_dError;
				}
			}
		}
	}
}
