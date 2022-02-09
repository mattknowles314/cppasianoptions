#ifndef AsianOptions_h
#define AsianOptions_h
#include<cmath>
#include "AvgPrices.h"
#include<stdio.h>

using namespace std;
//inputting and displaying option data
int GetOptionInputData(int& N, double& K){
    cout << "---ENTER OPTION DATA---" << endl;
    cout << "N: "; cin >> N;
    cout << "K: "; cin >> K;
    cout << endl; //Newline just for aesthetics in console output
    return 0;
}

// pricing Asian option by iterating over the paths x
// that change from 0 to (2^N)-1, for each x
// find the corresponding payoff and the probability using
// the functions from AvgPrices
double Price(double S0, double U, double D, double R, int N, double K, double (*Payoff)(double z, double K),double (*AvgType)(double* Prices, int N)){
    double disc = pow((1+R),(-1*N)); //Define this discounting factor now to use it later
    const int rows = pow(2,N)-1; //There are 2^N paths, but we start at 0 for indexing so minus 1 here to stay consistent
    const int cols = N; //We define this as a constant in order to be able to construct arrays

    //Create a 2^N x N matrix for storing the paths
    int paths[rows][cols];
    int (*r)[cols] = paths;

    //Generate paths by index
    for(int x=0; x<=rows;x++){
        int tempL[cols];
        int *t = tempL;
        GenPathByNumber(x,N,t);
        for(int i=0; i<N; i++){
            r[x][i] = t[i];
        }
    }

	//TEST: OUTPUT PATHS
	for(int x=0; x<=rows;x++){
		cout << "x = " << x << "\t";
		for(int i=0; i<N;i++){
			cout<<r[x][i];
		}
		cout << "\n" << endl;
	}

    //Create empty array for containg the probabilities of each path
    double pathProbs[rows];
    for(int i=0;i<=rows;i++){
        pathProbs[i] = GenProbabilityByPath(U,D,R,r[i],N);
    }

    //Create an empty 2^N x N matrix to stor prices along the paths
    double prices[rows][cols];
    double (*s)[cols] = prices;
    
    for(int x=0; x<=rows; x++){
        int *t = paths[x];
        double temp[cols];
        double *u = temp;
        GenProbabilityByPath(U,D,R,t,N);
    }

    //Create empty array of payoffs
    double payoffs[rows];

    //Loop through each path x and calculate payoff along that path
    for(int x=0; x<=rows; x++){
        double avgPrice = (*AvgType)(s[x],N);
        payoffs[x] = (*Payoff)(avgPrice,K);
    }

    //Calculate expected payoff
    double expPayoff = 0;
    for(int x=0; x<=rows; x++){
        expPayoff += (pathProbs[x]*payoffs[x]);
    }
    
    //Return the price of the option by discounting the epected payoff
    return disc*expPayoff;
}

//computing asian call payoff
double AsianCallPayoff(double avgPrice, double K){
    double null = 0;
    double t = avgPrice-K;
    return max(t, null);
}

//computing asian put payoff
double AsianPutPayoff(double avgPrice, double K){
    double null = 0;
    double t = K-avgPrice;
    return max(t,null);
}

#endif
