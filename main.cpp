#include <iostream>
#include "AsianOptions.h"
#include "AvgPrices.h"
#include "BinModel.h"
#include <cmath>
using namespace std;

int main(){
    double S0, U, D, R, K;
    int N;
    GetInputData(S0,U,D,R);
    GetOptionInputData(N,K);

    //Function pointers

    //Call payoff
    double (*ac)(double z, double K);
    ac = &AsianCallPayoff;

    //Put payoff
    double (*ap)(double z, double K);
    ap = &AsianPutPayoff;

    //Arithmetic averaging 
    double (*arith)(double* Prices, int N);
    arith = &ArAverage;

	//Geometric averaging
    double (*geom)(double* Prices, int N);
    geom = &GeAverage;

    //Price the option
    double callArith = Price(S0,U,D,R,N,K,ac,arith);
    double callGeom = Price(S0,U,D,R,N,K,ac,geom);
    double putArith = Price(S0,U,D,R,N,K,ap,arith);
    double putGeom = Price(S0,U,D,R,N,K,ap,geom);

    cout << "---PRICES FOR THE ENTERED DATA---" << endl;
    cout << "Call Option with Arithmetic Averaging: " << callArith << endl;
    cout << "Call Option with Geometric Averaging: " << callGeom << endl;
    cout << "Put Option with Arithmetic Averaging: " <<putArith << endl;
    cout << "Put Option with Geometric Averaging: " <<putGeom << endl;

	cout << "---PROGRAM TERMINATED---" << endl;

    return 0;
}
