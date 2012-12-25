#include "NeuralNet.h"
#include "ImageProc.h"

void main(){
	CNeuralNet myNet(64, 1, 2, 64);

	vector<v_double> trainingset;
	vector<v_double> outputset;

	vector<double> tset;

	MyImage A("./trainingset/A.txt");
	MyImage B("./trainingset/B.txt");
	MyImage C("./trainingset/C.txt");
	MyImage D("./trainingset/D.txt");
	MyImage E("./trainingset/E.txt");

	trainingset.push_back(A.Image);
	outputset.push_back(A.Result);
	trainingset.push_back(B.Image);
	outputset.push_back(B.Result);

	myNet.Backpropagation(trainingset, outputset);

	printf("A\n");
	for(int i=0; i< 64;){
		for(int k=0; k<8; k++){
			printf("%d",(int)trainingset.at(0).at(i++));
		}
		printf("\n");
	}

	printf("expect: %f output: %f\n",outputset.at(0).at(0),myNet.Update(trainingset.at(0)).at(0));

	printf("B\n");
	for(int i=0; i< 64;){
		for(int k=0; k<8; k++){
			printf("%d",(int)trainingset.at(1).at(i++));
		}
		printf("\n");
	}

	printf("expect: %f output: %f\n",outputset.at(1).at(0),myNet.Update(trainingset.at(1)).at(0));

	return;
}

/*
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

*/