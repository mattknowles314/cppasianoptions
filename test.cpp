//TESTING

#include <iostream>
#include <cmath>
#include "AsianOptions.h"
#include "AvgPrices.h"
#include "BinModel.h"

using namespace std;

int main(){

	//Keeping the input data the same as to keep everything consistent
	double S0=50;
	double U=5;
	double D=1;
	double R=3;
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

	cout << "CALL: " << callArith << endl;
	cout << "PUT: " << putArith << endl;

	return 0;
}
