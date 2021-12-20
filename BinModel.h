#ifndef BinModel_h
#define BinModel_h

//computing risk-neutral probability
double RiskNeutProb(double U, double D, double R){
    return (R-D)/(U-D);
}

//inputting, displaying and checking model data
int GetInputData(double& S0, double& U, double& D, double& R);

#endif