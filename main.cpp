#include <iostream>
#include "AsianOptions.h"
#include "AvgPrices.h"
#include "BinModel.h"
#include <cmath>
using namespace std;

int main(){
    cout << "Testing" << endl;
    double S0, U, D, R, K;
    int N;
    bool opType = 1; //Type of option, 1 for call, 0 for put. 
    GetInputData(S0,U,D,R);
    GetOptionInputData(N,K);
    const int pN = pow(2,N)-1;
    
    //Need to create empty 2D array for the x values.
    //(2^N)-1 arrays of length N.

    const int rowCount = pow(2,N)-1;
    const int colCount = N;

    double paths[rowCount][colCount];
    double (*r)[colCount] = paths;

    //Currently breaks at N=5?!
    for (int  x = 0; x <= rowCount; x++)
    {
        int tempL[colCount];
        int *t = tempL;
        GenPathByNumber(x,N,t);
        for(int i = 0; i < N; i++){
            r[x][i] = t[i];
        }
    }
    
    //Test that the output paths are as expected
    for(int k=0; k<=rowCount; k++){
        for(int l=0;l<N;l++){
            cout << r[k][l];
        }
        cout << "END" << endl;
    }

    cout << "TEST COMPLETE" << endl;
    
    

    return 0;
}