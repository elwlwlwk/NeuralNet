#include "NeuralNet.h"
#include "ImageProc.h"
#include "Brain.h"

void main(){
	CNeuralNet myBrain(64, 2, 2, 64);
	
	vector<v_double> trainingset;
	vector<v_double> outputset;

	vector<double> tset;

	MyImage A("./trainingset/A.txt");
	MyImage B("./trainingset/B.txt");
	MyImage C("./trainingset/C.txt");
	MyImage D("./trainingset/D.txt");

	MyImage _A("./trainingset/_A.txt");
	MyImage _B("./trainingset/_B.txt");
	MyImage _C("./trainingset/_C.txt");
	MyImage _D("./trainingset/_D.txt");

	trainingset.push_back(A.Image);
	outputset.push_back(A.Result);
	trainingset.push_back(B.Image);
	outputset.push_back(B.Result);
	trainingset.push_back(C.Image);
	outputset.push_back(C.Result);
	trainingset.push_back(D.Image);
	outputset.push_back(D.Result);

	trainingset.push_back(_A.Image);
	outputset.push_back(_A.Result);
	trainingset.push_back(_B.Image);
	outputset.push_back(_B.Result);
	trainingset.push_back(_C.Image);
	outputset.push_back(_C.Result);
	trainingset.push_back(_D.Image);
	outputset.push_back(_D.Result);


	myBrain.Backpropagation(trainingset, outputset);
	

	while(1){
		char str[100];

		memset(str, 0, sizeof(str));
		printf("input file name:");
		scanf("%s", str);
		MyImage MyImg(str);

		vector<v_double> input;
		input.push_back(MyImg.Image);

		printf("%f %f\n",myBrain.Update(input.at(0)).at(0),myBrain.Update(input.at(0)).at(1));
	}

	return;
}


/*
void main(){
	CBrain myBrain(5, 64, 1, 2, 64);
	
	vector<v_double> trainingset[5];
	vector<v_double> outputset[5];

	vector<double> tset;

	MyImage A("./trainingset/A.txt");
	MyImage B("./trainingset/B.txt");
	MyImage C("./trainingset/C.txt");
	MyImage D("./trainingset/D.txt");
	MyImage E("./trainingset/E.txt");

	MyImage _A("./trainingset/_A.txt");
	MyImage _B("./trainingset/_B.txt");
	MyImage _C("./trainingset/_C.txt");
	MyImage _D("./trainingset/_D.txt");
	MyImage _E("./trainingset/_E.txt");

	trainingset[0].push_back(A.Image);
	outputset[0].push_back(A.Result);
	trainingset[1].push_back(B.Image);
	outputset[1].push_back(B.Result);
	trainingset[2].push_back(C.Image);
	outputset[2].push_back(C.Result);
	trainingset[3].push_back(D.Image);
	outputset[3].push_back(D.Result);
	trainingset[4].push_back(E.Image);
	outputset[4].push_back(E.Result);

	trainingset[0].push_back(_A.Image);
	outputset[0].push_back(_A.Result);
	trainingset[1].push_back(_B.Image);
	outputset[1].push_back(_B.Result);
	trainingset[2].push_back(_C.Image);
	outputset[2].push_back(_C.Result);
	trainingset[3].push_back(_D.Image);
	outputset[3].push_back(_D.Result);
	trainingset[4].push_back(_E.Image);
	outputset[4].push_back(_E.Result);

	for(int i=0; i<5; i++){
		myBrain.train(i, trainingset[i], outputset[i]);
	}
	
	for(int i=0; i<5; i++){
		printf("%d: ",i); 
		printf("%d\n", myBrain.update(trainingset[i].at(0)));
	}

	myBrain.Save();

	while(1){
		char str[100];

		memset(str, 0, sizeof(str));
		printf("input file name:");
		scanf("%s", str);
		MyImage MyImg(str);

		vector<v_double> input;
		input.push_back(MyImg.Image);

		int out= myBrain.update(input.at(0));

		switch(out){
		case 0:
			printf("A\n");
			break;
		case 1:
			printf("B\n");
			break;
		case 2:
			printf("C\n");
			break;
		case 3:
			printf("D\n");
			break;
		case 4:
			printf("E\n");
			break;
		}

	}

	return;
}
*/


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

	tset.clear();cv
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