//TESTING

#include <iostream>
#include <cmath>
#include "AsianOptions.h"
#include "AvgPrices.h"
#include "BinModel.h"

using namespace std;

int main(){

	//Keeping the input data the same as to keep everything consistent
	double S0=60;
	double U=0.7;
	double D=-0.1;
	double R=0.1;
	double K=55;
	int N=3;
	
	double (*ac)(double z, double K);
	ac = &AsianCallPayoff;

	double (*ap)(double z, double K);
	ap = &AsianPutPayoff;

	double (*arith)(double* Prices, int N);
	arith = &ArAverage;
	
	double (*geom)(double* Prices, int N);
	geom = &GeAverage;

	//This is returning 0 when it definately should be
	double callArith = Price(S0,U,D,R,N,K,ac,arith);
	double putArith = Price(S0,U,D,R,N,K,ap,arith);

	cout << callArith << endl;
	cout << putArith << endl;

	return 0;



}
