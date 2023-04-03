#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>

int main(){

// Grid initalisation.
double tau = 0.95, x = 1.00, dx = 0.05, dtau = 0.001;
double ntau = tau/dtau + 1 /* 951 */, nx = x/dx + 1 /* 21 */;
double grid[951][21];

// Initialise grid to zeros.
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ntau; j++){
            grid[j][i] = 0.0;
        }
    }

// Define the inital conditions
    for(int i = 0; i < nx; i++){
        grid[0][i] = 0.0;
    }

    for(int j = 1; j < ntau; j++){
        grid[j][0] = 1.0;
        grid[j][20] = 1.0;
    }
// Use finite differencing method to find numerical solution.
    for(int j = 0; j < ntau - 1; j++){
        for(int i = 1; i < nx - 1; i++){
            grid[j+1][i] = (dtau/pow(dx,2))*grid[j][i-1] + (1-2*(dtau/pow(dx,2)))*grid[j][i] + (dtau/pow(dx,2))*grid[j][i+1];
        }
        std::cout << std::endl;
    }

char const* m[951][21];

// Color code for the terminal plot
for(int j = 0; j < ntau; j++){
    for(int i = 0; i < nx; i++){
		 if(grid[j][i] > 0.9 && grid[j][i] <=1){
		    m[j][i] = "\033[1;31m*\033[0m";
        }
		 else if(grid[j][i] > 0.8 && grid[j][i] <= 0.9){
		    m[j][i] = "\033[1;32m+\033[0m";
        }
		 else if(grid[j][i] > 0.7 && grid[j][i] <= 0.8){
		    m[j][i] = "\033[1;33m-\033[0m";
        }
		 else if(grid[j][i] > 0.6 && grid[j][i] <= 0.7){
		    m[j][i] = "\033[1;34m#\033[0m";
        }
		 else if(grid[j][i] > 0.5 && grid[j][i] <= 0.6){
		    m[j][i] = "\033[1;35m%\033[0m";
        }
		 else if(grid[j][i] > 0.4 && grid[j][i] <= 0.5){
		    m[j][i] = "\033[1;36m&\033[0m";
        }
		 else if(grid[j][i] > 0.3 && grid[j][i] <= 0.4){
		    m[j][i] = "\033[1;37m@\033[0m";
        }
		 else if(grid[j][i] > 0.2 && grid[j][i] <= 0.3){
		    m[j][i] = "=";
        }
		 else if(grid[j][i] > 0.1 && grid[j][i] <= 0.2){
		    m[j][i] = "!";
        }
		 else if(grid[j][i] >= 0.0 && grid[j][i] <= 0.1){
		    m[j][i] = ".";
        }
		 else{
		    m[j][i] = "err";}
        }
    }

    for(int j = 0; j < ntau; j++){
        std::cout << "|  ";
        for(int i = 0; i < nx; i++){
            std::cout << m[j][i] << " ";
        }
        std::cout << "  |          t = " << std::setprecision(3) << j*dtau; std::cout << std::endl;
    }
    return 0;
}
