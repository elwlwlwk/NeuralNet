#include "NeuralLib.h"

double RandomClamped(){

	int k= rand()%2000;
	k-= 1000;
	return (double)k/1000;
}

double Sigmoid(double activation, double response){
	return 1/(1+pow(M_E, (-1*activation)/response));
}