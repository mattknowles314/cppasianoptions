//TESTING

#include <iostream>
#include <cmath>
#include "AsianOptions.h"
#include "AvgPrices.h"
#include "BinModel.h"
#include <fstream>

using namespace std;

int main(){

	//Keeping the input data the same as to keep everything consistent
	double S0s[10];
	double s0 = 90;
	double U=0.72;
	double D=0.01;
	double R=0.04;
	double K=100;
	int N=5;
	
	double (*ac)(double z, double K);
	ac = &AsianCallPayoff;

	double (*ap)(double z, double K);
	ap = &AsianPutPayoff;

	double (*arith)(double* Prices, int N);
	arith = &ArAverage;
	
	double (*geom)(double* Prices, int N);
	geom = &GeAverage;

	double callArithPrices[10];
	
	S0s[0] = s0;
	
	/*
	int i = 0;
	while(i<10){
		callArithPrices[i] = Price(S0s[i],U,D,R,N,K,ac,arith);
		S0s[i+1] = S0s[i]+10;
		i++;
	}	
	
	for(int j=0;j<10;j++){
		cout << S0s[j] << "," << callArithPrices[j] << endl;
	}*/

	cout << Price(s0,U,D,R,N,K,ac,arith) << endl;

	//Investigating why we get probabilities in excess of 90

	int tempPath[5] = {0,0,0,0,0};
	int *a = tempPath;
	//cout << GenProbabilityByPath(U,D,R,a,N) << endl;

	

	return 0;
}
