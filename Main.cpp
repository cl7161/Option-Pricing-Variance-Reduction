#include <iostream>
#include "PathDepOption.h"
#include "GmtrAsianCall.h"

using namespace std;
using namespace fre;

int main()
{
    double S0=100.0, r=0.03, sigma=0.2;
    MCModel Model(S0,r,sigma);

    double T =1.0/12.0, K=100.0;
    int m=30;

    ArthmAsianCall Option(T,K,m);
    GmtrAsianCall  CVOption(T,K,m);

    long N=30000;
    double epsilon =0.001;
    Option.PriceByVarRedMC(Model,N,CVOption,epsilon);
    cout << "Price by Variance Reduction Techniques:" << endl
        << "Arithmetic call price = " << Option.GetPrice() << endl
        << "Error = " << Option.GetPricingError() << endl 
        << "delta = " << Option.GetDelta() << endl << endl;


    Option.PriceByMC(Model,N,epsilon);
    cout << "Price by direct Monte Carlo:" << endl
        << "Arithmetic call price = " << Option.GetPrice() << endl
        << "Error = " << Option.GetPricingError() << endl
        << "delta = " << Option.GetDelta() << endl << endl;

    return 0;
}


/*
Price by Variance Reduction Techniques:
Arithmetic call price = 1.42613
Error = 0.000139987
delta = 0.520758

Price by direct Monte Carlo:
Arithmetic call price = 1.41244
Error = 0.0119371
delta = 0.524992
*/

