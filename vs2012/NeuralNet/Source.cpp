#include "NeuralNet.h"

void main(){
	CNeuralNet myNet(3, 1, 2, 2);

	vector<v_double> trainingset;
	vector<v_double> outputset;

	vector<double> tset;
	tset.push_back(0);
	tset.push_back(0);
	tset.push_back(0);


	trainingset.push_back(tset);

	tset.clear();
	tset.push_back(0);
	tset.push_back(0);
	tset.push_back(1);
	trainingset.push_back(tset);

	tset.clear();
	tset.push_back(0);
	tset.push_back(1);
	tset.push_back(0);
	trainingset.push_back(tset);

	tset.clear();
	tset.push_back(0);
	tset.push_back(1);
	tset.push_back(1);
	trainingset.push_back(tset);

	tset.clear();
	tset.push_back(1);
	tset.push_back(0);
	tset.push_back(0);
	trainingset.push_back(tset);
	
	tset.clear();
	tset.push_back(1);
	tset.push_back(0);
	tset.push_back(1);
	trainingset.push_back(tset);
	
	tset.clear();
	tset.push_back(1);
	tset.push_back(1);
	tset.push_back(0);
	trainingset.push_back(tset);
	
	tset.clear();
	tset.push_back(1);
	tset.push_back(1);
	tset.push_back(1);
	trainingset.push_back(tset);
	
	vector<double> dset;

	dset.push_back(1);
	outputset.push_back(dset);
	dset.clear();

	dset.push_back(0);
	outputset.push_back(dset);
	dset.clear();

	dset.push_back(1);
	outputset.push_back(dset);
	dset.clear();

	dset.push_back(0);
	outputset.push_back(dset);
	dset.clear();

	dset.push_back(1);
	outputset.push_back(dset);
	dset.clear();
	
	dset.push_back(0);
	outputset.push_back(dset);
	dset.clear();
	
	dset.push_back(1);
	outputset.push_back(dset);
	dset.clear();
	
	dset.push_back(1);
	outputset.push_back(dset);
	dset.clear();
	
	myNet.Backpropagation(trainingset, outputset);

	printf("training end\n");

	for(int i=0; i< trainingset.size(); i++){
		printf("%f, %f, %f\n", trainingset[i][0], trainingset[i][1], myNet.Update(trainingset[i]).at(0));
	}

	vector<double> inputs;
	inputs.push_back(1);
	inputs.push_back(1);
	inputs.push_back(1);
	printf("%f\n", myNet.Update(inputs).at(0));

	myNet.SaveWeights("fuck.w");

	CNeuralNet myNet2("fuck.w");
	for(int i=0; i< trainingset.size(); i++){
		printf("%f, %f, %f\n", trainingset[i][0], trainingset[i][1], myNet2.Update(trainingset[i]).at(0));
	}


	return;
}