#include <iostream>
#include "AsianOptions.h"
#include "AvgPrices.h"
#include "BinModel.h"
using namespace std;

int main(){
    cout << "Testing" << endl;
    double S0 = 50;
    double U = 0.5;
    double D = 0.3;
    int N = 5;
    int testPath[5] = {0,0,0,1,0};
    int *p = testPath;
    double testPrice[6] = {0};
    double *q = testPrice;
    GenPricesByPath(S0,U,D,p,N,q);
    for(int j=0;j<N;j++){
        cout<<testPrice[j]<<endl;
    }
    cout << "Test complete" << endl;
    return 0;
}