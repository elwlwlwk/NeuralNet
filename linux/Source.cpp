#include "NeuralNet.h"
#include <stdio.h>

int main(){
	CNeuralNet myNet(2, 1, 2, 2);

	vector<v_double> trainingset;
	vector<v_double> outputset;

	int Cleared= 0;
	while(Cleared< 4){
		Cleared= 0;
		vector<double> input;
		vector<double> destout;
		input.push_back(0);
		input.push_back(0);
		destout.push_back(0);
		
		myNet.Backpropagation(input, destout);
		input.push_back(0);
		input.push_back(0);
		vector<double> output= myNet.Update(input);
		
		//printf("0, 0, %f\n", output[0]);
		
		input.clear();
		destout.clear();
		output.clear();
		/////////////////////////////////////////////////////////////////
		input.push_back(0);
		input.push_back(1);
		destout.push_back(1);
		
		myNet.Backpropagation(input, destout);
		input.push_back(0);
		input.push_back(1);
		output= myNet.Update(input);

		//printf("0, 1, %f\n", output[0]);

		input.clear();
		destout.clear();
		output.clear();
		/////////////////////////////////////////////////////////////////
		input.push_back(1);
		input.push_back(0);
		destout.push_back(1);
		
		myNet.Backpropagation(input, destout);
		input.push_back(1);
		input.push_back(0);
		output= myNet.Update(input);

		//printf("1, 0, %f\n", output[0]);

		input.clear();
		destout.clear();
		output.clear();
		////////////////////////////////////////////////////////////////
		input.push_back(1);
		input.push_back(1);
		destout.push_back(0);
		
		myNet.Backpropagation(input, destout);
		input.push_back(1);
		input.push_back(1);
		output= myNet.Update(input);

		//printf("1, 1, %f\n", output[0]);

		input.clear();
		destout.clear();
		output.clear();


		//////////////////////////////////////////
		//////////////////////////////////////////
		input.push_back(0);
		input.push_back(0);
		output= myNet.Update(input);
		printf("0, 0, %f\n", output[0]);
		if(output[0]< 0.2){
			//printf("0, 0, 0\n");
			Cleared++;
		}
		input.clear();
		destout.clear();
		output.clear();
		input.push_back(0);
		input.push_back(1);
		output= myNet.Update(input);
		printf("0, 1, %f\n", output[0]);
		if(output[0]>0.8){
			//printf("0, 1, 1\n");
			Cleared++;
		}
		input.clear();
		destout.clear();
		output.clear();
		input.push_back(1);
		input.push_back(0);
		output= myNet.Update(input);
		printf("1, 0, %f\n", output[0]);
		if(output[0]>0.8){
			//printf("1, 0, 1\n");
			Cleared++;
		}
		input.clear();
		destout.clear();
		output.clear();
		input.push_back(1);
		input.push_back(1);
		output= myNet.Update(input);
		printf("1, 1, %f\n", output[0]);
		if(output[0]< 0.2){
			//printf("1, 1, 0\n");
			Cleared++;
		}
		input.clear();
		destout.clear();
		output.clear();

	}
	vector<double> input, output;
	input.push_back(0);
		input.push_back(0);
		output= myNet.Update(input);

		if(output[0]< 0.2){
			printf("0, 0, 0\n");
			Cleared++;
		}
		input.clear();
		output.clear();
		input.push_back(0);
		input.push_back(1);
		output= myNet.Update(input);
		if(output[0]>0.8){
			printf("0, 1, 1\n");
			Cleared++;
		}
		input.clear();
		output.clear();
		input.push_back(1);
		input.push_back(0);
		output= myNet.Update(input);
		if(output[0]>0.8){
			printf("1, 0, 1\n");
			Cleared++;
		}
		input.clear();
		output.clear();
		input.push_back(1);
		input.push_back(1);
		output= myNet.Update(input);
		if(output[0]< 0.2){
			printf("1, 1, 0\n");
			Cleared++;
		}
		input.clear();
		output.clear();

	return 0;
}
