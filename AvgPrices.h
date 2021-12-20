#ifndef AvgPrices_h
#define AvgPrices_h
#include <cmath>
#include <stdlib.h>
#include "BinModel.h"

// generates a path with a number x from 0 to (2^N)-1
// returns a path with number according to convention
// and writes this path into the array Path of length N
// generates an array of prices along the path and writes them into the array Prices of length N

void GenPathByNumber(int x, int N, int* Path){
    //If x is 0, then we can just return a path of 0s. If not, we can just generate all the binary numbers between 1 and 2^N-1
    if(x==0){
        for(int j=0;j<N;j++){
            Path[j] = 0;
        }
    }else if(x==pow(2,N)-1){
        for(int j=0;j<N;j++){
            Path[j] = 1;
        }
    }else{
        cout << "EMPTY" << endl;
        
    }
}

void GenPricesByPath(double S0, double U,double D, int* Path, int N, double* Prices){
    Prices[0] = S0;
    for(int j=0;j<N;j++){
        if(Path[j]==0){
            Prices[j+1] = Prices[j]*(1+U);
        } else{
            Prices[j+1] = Prices[j]*(1+D);
        }
    }
}

// generates a probability of the path
double GenProbabilityByPath(double U,double D, double R, int* Path, int N){
    int i = 0;
    for(int j=0;j<N;j++){
        if(Path[j]==1){
            i+=1;
        }
    }
    double q = RiskNeutProb(U,D,R);
    return pow(q,i)*pow(1-q,N-i);
}

//computing arithmetic average of the array of prices
double ArAverage(double* Prices, int N){
    double sum = 0;
    for(int j=1; j==N; j++){
        sum+=Prices[j];
    }
    return sum/N;
}

//computing geometric average of the array of prices
double GeAverage(double* Prices, int N){
    double avg = 1;
    for(int j=1; j==N; j++){
        avg*=Prices[j];
    }
    return pow(avg,1.0/N);
}

#endif