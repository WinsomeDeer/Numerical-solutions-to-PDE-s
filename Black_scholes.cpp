#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#include <math.h> 
#include <random>

double option(double S, double K, int T, double r, double vol, double eps){
    double d1, d2;

    d1 = eps*(log(S/K) + r*T + pow(vol, 2) * T/2)/vol/sqrt(T);
    d2 = eps*(log(S/K) + r*T - pow(vol, 2) * T/2)/vol/sqrt(T);
    
    std::normal_distribution<double> Nd1();
}


// Main finite differencing method.
int main(){

    // Initial values.
    double r = 0.01, vol = 0.01, S = 100, K = 98, T = 1;
    double dt = 0.01, ds = 0.01;
    double S_[100];

    // Initialise the vector.
    for(int s = 0; s < 150; s += ds){
        S_[s] = std::max(S - K, 0);
    }

    // Boundary condition - 

    return 0;
}
