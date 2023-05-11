#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <algorithm> 
#include <cmath>
#include <math.h> 
#include <random>

// Cumulative normal distribution function.
double normal_cdf(double x, double mu, double sigma){
    return 0.5*(1 + erf((x-mu)/(sigma*sqrt(2))));
}

// Function to calculate the analytic solution of the BS PDE.
double option(double S, double K, int T, double r, double vol, double eps){

    double d1, d2, Nd1, Nd2;

    d1 = eps*(log(S/K) + r*T + pow(vol, 2) * T/2)/vol/sqrt(T);
    d2 = eps*(log(S/K) + r*T - pow(vol, 2) * T/2)/vol/sqrt(T);
    Nd1 = normal_cdf(d1, 0, 1);
    Nd2 = normal_cdf(d2, 0, 1);
    return (eps*S*Nd1 - eps*exp(-r*T)*K*Nd2);
}

// Main finite differencing method.
int main(){
    // Initial values.
    int N = 30, n = 200;
    double r = 0.04, vol = 0.2, K = 13, t, T = 2, df, D2;
    double dt = 0.0004, dx = 0.15, du = 0.15;
    double X[200], U[200], W[200], O[200];
    X[0] = 0.001, W[0] = 0;

    // Initialise the vector.
    for(int x = 0; x < n-1; x++){
        X[x+1] = X[x] + dx;
    }

    // Initialise the vector.
    for(int u = 0; u < n; u++){
        U[u] = std::max(X[u] - double(K), 0.0);
    }

    t = T;
    // Finite differencing method.
    while(t > dt + pow(10, 6)){
        t -= dt;
        // For loop.
        for(int i = 1; i < n-1; i++){
            df = 1/(1 + dt*r);
            D2 = pow((X[i]*vol), 2) * dt * (U[i+1] - 2*U[i] + U[i-1])/2/pow(N/n, 2);
            W[i] = df*(U[i] + D2 + r*X[i]*dt*(U[i+1] - U[i-1])/2/(N/n));
        }
        for(int i = 1; i < n-1; i++){
            U[i] = W[i];
        }
    }

    // Initialise the options vector.
    for(int o = 0; o < n; o++){
        O[o] = 0;
    }

    // Calulcate the analytic solution of the BS PDE.
    for(int o = 0; o < n; o++){
        O[o] = option(X[o], K, T, r, vol, 1);
    }

    return 0;
}
