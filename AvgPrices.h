#ifndef AvgPrices_h
#define AvgPrices_h
#include <cmath>
#include <stdlib.h>
#include "BinModel.h"

// generates a path with a number x from 0 to (2^N)-1
// returns a path with number according to convention
// and writes this path into the array Path of length N
// generates an array of prices along the path and writes them into the array Prices of length N

//Recursive function for calculating the factorial of an integer n, n!
int factorial(int n){
    int result = 1;
    while (n>1) {
        result *= n--;
    }
    return result;
}

//Function for calculating the nCr value
int choose(int n, int k){
    return (factorial(n)/(factorial(k)*factorial(n-k)));
}

void getNodeAndPos(int x, int n, int* temp){
    if(x == 0){
        temp[0] = 0;
        temp[1] = 0;
    } else if(x==pow(2,n)-1){
        temp[0] = n;
        temp[1] = 0;
    } else{
        int count = x;
        for(int j = 0; j<n; j++){
            int currentNode = choose(n,j);
            int inCount = currentNode;
            while(inCount > 0){
                if(count == 0){
                    temp[0] = j;
                    temp[1] = currentNode-inCount;
                }
                inCount-=1;
                count-=1;
            }
        }
    }
}

void getParentAndIndex(int node, int n, int pos, int* temp){
    if(node == 0){
        int temp[3] = {0};
    }else if(node == n){
        temp[0] = 1;
        temp[1] = 0;
        temp[2] = n-1; 
    }
    int p1 = choose(n-1,node-1);
    if(p1 > pos){
        temp[0] = 1;
        temp[1] = pos;
        temp[2] = node-1;        
    } else{
        temp[0] = 0;
        temp[1] = pos-p1;
        temp[2] = node;
    }
}

int getPathRecurse(int pos, int n, int node, int* path, int count){
    if(n==0){
        return 99;
    }
    int temp[3];
    int *q = temp;
    getParentAndIndex(node, n, pos, q);
    int inPos = temp[1];
    int inNode = temp[2];
    path[count] = temp[0];
    count+=1;
    return getPathRecurse(inPos,n-1,inNode,path,count);
}

int getPath(int x, int n, int* path){
    int count = 0;
    int temp[2] = {0};
    int *p = temp;
    getNodeAndPos(x,n,p);
    int node = temp[0];
    int pos = temp[1];

    return getPathRecurse(pos,n,node,path,count);    
}

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
        int n = N;
        getPath(x,n,Path); 
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
    for(int j=1; j<N; j++){
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