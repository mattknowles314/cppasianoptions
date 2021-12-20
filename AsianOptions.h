#ifndef AsianOptions_h
#define AsianOptions_h

using namespace std;
//inputting and displaying option data
int GetInputData(int& N, double& K);

// pricing Asian option by iterating over the paths x
// that change from 0 to (2^N)-1, for each x
// find the corresponding payoff and the probability using
// the functions from AvgPrices
double Price(double S0, double U, double D, double R, int N, double K, double (*Payoff)(double z, double K),double (*AvgType)(double* Prices, int N));

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