#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>

#define M_E			2.71828182845904523536
#define M_BIAS		-1
#define M_SIGRESP	1
#define M_LEARNRATE 0.05
#define M_ACERR 0.05

double RandomClamped();

double Sigmoid(double activation, double responswe);