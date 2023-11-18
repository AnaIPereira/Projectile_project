#include <iostream> 
#include <cmath>
#include <vector>
#include <fstream>
#include <random>
using namespace std;

// function to return optimal angle
void theta_c( double v0, double g, double d)
{
    double sr=1+2*g/(pow(v0,2))-pow(g,2)*pow(d,2)/pow(v0,4);
    double x=pow(v0,2)/(2*g)*(1+sqrt(sr));
    double thetac = atan(x);
}

// function to return angle from gaussian function
double rand_angle(double mean, double stddev) {
    random_device rd; 
    mt19937 gen(rd());
    normal_distribution<double> distribution(mean, stddev);
    return distribution(gen);
} 

int main() {
    double mean = 100;
    double stddev = 300;

    double t = rand_angle(mean, stddev);
    cout << "Random Angle: " << t << " radians" << endl;

    return 0;
}

