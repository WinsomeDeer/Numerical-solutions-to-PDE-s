#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>

int main(){

// Initialise variables.
    double X = 10, T = 10, C, dx = 1/X, dt = 1/T; 
    double u[11][11];

// Initialise grid to zeros.
    for(int x = 0; x <= X; x++){
        for(int t = 0; t <= T; t++){
            u[x][t] = 0.0;
        }
    }

// Initliase the grid with initial values.
    for(int x = 0; x <= X-1; x++){
        u[x][0] = u[x][1] = sqrt(x);
    }

// FDM.
    for(int t = 1; t <= T-1; t++){
        for(int x = 1; x <= X-1; x++){
            u[x][t] = u[x-1][t] + u[x+1][t] - u[x][t-1];
        }
    }

// Print the values.
    for(int t = 0; t <= T; t++){
        for(int x = 0; x <= X; x++){
            std::cout << u[x][t] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
