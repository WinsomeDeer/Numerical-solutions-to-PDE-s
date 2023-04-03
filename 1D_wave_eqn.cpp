#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>

int main(){

// Initialise variables.
    double X = 10, T = 10; 
    double u[11][11];

// Initialise grid to zeros.
    for(int x = 0; x <= X; x++){
        for(int t = 0; t <= T; t++){
            u[x][t] = 0.0;
        }
    }

// FDM.
    for(int t = 0; t <= T; t++){
        
    }

    return 0;
}
