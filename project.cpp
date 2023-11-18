#include <iostream> 
#include <cmath>
#include <vector>
#include <fstream>
#include <random>
using namespace std;

// function to return optimal angle
double theta_c(double v0, double g, double d)
{
    double sr=1+2*g/(pow(v0,2))-pow(g,2)*pow(d,2)/pow(v0,4);
    double x=pow(v0,2)/(2*g)*(1+sqrt(sr));
    double thetac = atan(x);
    return thetac;
}

// function to return angle from gaussian function
double rand_angle(double mean, double stddev) {
    random_device rd; 
    mt19937 gen(rd());
    normal_distribution<double> distribution(mean, stddev);
    return distribution(gen);
} 


int main() 
{
    double vel=450;
    double grav=9.8;
    double x=100;

    double thet=theta_c(vel,grav,x);
    cout << "Optimal Angle: " << thet << " radians" << endl;

    double mean = 0;
    double stddev = 3*M_PI/180;
    double t = rand_angle(mean, stddev);
    cout << "Random Angle: " << t << " radians" << endl;
    return 0;
}

