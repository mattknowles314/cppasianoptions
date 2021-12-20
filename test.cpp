#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
using namespace std;

int factorial(int n){
    int result = 1;
    while (n>1) {
        result *= n--;
    }
    return result;
}

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

int getPathRecurse(int pos, int n, int node, int* path){
    if(n==0){
        return 99;
    }
    int temp[3];
    int *q = temp;
    getParentAndIndex(node, n, pos, q);
    int inPos = temp[1];
    int inNode = temp[2];
    //This is broken, need to append to the array not just keep changing the last element
    path[[sizeof(path)/sizeof(path[0])-1]] = temp[0];
    return getPathRecurse(inPos,n-1,inNode,path);
}

int getPath(int x, int n, int* path){
    int temp[2] = {0};
    int *p = temp;
    getNodeAndPos(x,n,p);
    int node = temp[0];
    cout << "NODE: " << node << endl; 
    int pos = temp[1];
    cout << "POS: " << pos << endl;

    return getPathRecurse(pos,n,node,path);    
}

void GenPathByNumber(int x, int N, int* Path){ 
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

int main(){
    cout << "Calculating Path" << endl;
    int temp[2] = {0,1};
    int *p = temp;
    int testPath[4];
    int *q = testPath;
    getPath(3,3,q);
    cout << "GIVEN PATH" << endl;
    for(int i=0; i<4;i++){
        cout << testPath[0] << endl;
    }
    return 0;
}