#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
using namespace std;

int numbers[6] = {1,2,3,4,5,6};
int *p = numbers;
int sumNums(int x, int y){
    return x+y;
}

int sumAList(int (*sumNums)(int x, int y), int *listA){
    int sum = 0;
    for (int i = 0; i < 6; i+=2)
    {
        sum+=sumNums(listA[i],listA[i+1]);
    }
    return sum;
}

int main(){
    cout << sumAList(&sumNums,numbers);
    return 0;
}