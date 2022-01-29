#ifndef BinModel_h
#define BinModel_h

using namespace std;

//computing risk-neutral probability
double RiskNeutProb(double U, double D, double R){
    return (R-D)/(U-D);
}

//Checks the validity of the stock important parameters
bool isValid(double D, double R, double U){
    if(U>R && R>D && D>-1){ //-1 < D < R < U
        return 1;
    }
    else{
        return 0;
    }
}

//inputting, displaying and checking model data
int GetInputData(double& S0, double& U, double& D, double& R){
    cout << "---ENTER STOCK DATA---" << endl;
    cout << "S0: "; cin >> S0;
    cout << "U: "; cin >> U;
    cout << "D: "; cin >> D;
    cout << "R: "; cin >> R;
    if(isValid(D,R,U)){
        cout << "MESSAGE: STOCK DATA IS VALID, CONTINUING" << endl;
        return 0;
    } else{
        cout << "MESSAGE: STOCK DATA IS INVALID, PLEASE TRY AGAIN\n" << endl;
        GetInputData(S0,U,D,R);
        return 0;
    }
    cout << endl; //Newline just for aesthetics in console output
}

#endif