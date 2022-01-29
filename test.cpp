#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
    int f[3] = {1,2,3};
    int testList[2][3] = {{3,4,5},{6,7,8}};
    int (*p)[3] = testList;
    for(int i=0; i<3; i++){
        p[1][i]=f[i];
    }
    for(int i=0; i<3; i++){
        cout << testList[1][i] << endl;
    }
    return 0;
}