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
	double U=0.45;
	double D=0.35;
	double R=0.4;
	double K=50;
	int N=5;
	
	double (*ac)(double z, double K);
	ac = &AsianCallPayoff;

	double (*ap)(double z, double K);
	ap = &AsianPutPayoff;

	double (*arith)(double* Prices, int N);
	arith = &ArAverage;
	
	double (*geom)(double* Prices, int N);
	geom = &GeAverage;

	double putArithPrices[10];
	
	S0s[0] = s0;
	
	
	int i = 0;
	while(i<10){
		putArithPrices[i] = Price(S0s[i],U,D,R,N,K,ap,arith);
		S0s[i+1] = S0s[i]+10;
		i++;
	}	
	
	for(int j=0;j<10;j++){
		cout << S0s[j] << "," << putArithPrices[j] << endl;
	}
	
	system("pause");
	return 0;
}
