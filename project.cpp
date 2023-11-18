#include <iostream> 
#include <cmath>
#include <vector>
#include <fstream>
#include <random>
using namespace std;

// function to return optimal angle
//double theta_c(double v0, double g, double d)
//{
  //  double sr=1 + 2*g/pow(v0,2)*(-0.6-1/2*g*pow(d,2)/pow(v0,2));
    //double x=pow(v0,2)*(1 + sqrt(sr));
    //double thetac = atan(x);
    //return thetac;
//}

//opt angle

void opt(){
    double g=9.8;
    double v=450;
    double d=100;
    double h=-0.6;
    double a = -1/2*g*pow(d,2)/pow(v,2);
    double b = d;
    double c = h-1/2*g*pow(d,2)/pow(v,2);
    double tang=-b+sqrt(pow(b,2)-4*a*c)/(2*a);
    return atan(tang);
}

// function to return angle from gaussian function
double rand_angle(double mean, double stddev) 
{
    random_device rd; 
    mt19937 gen(rd());
    normal_distribution<double> distribution(mean, stddev);
    return distribution(gen);
} 

// function to compute the high at wich the bullet hits the target
double high(double h1, double v0, double g, double d, double angle)
{
    double y = h1 - 1/2*g*pow(d,2)/(pow(v0,2))*(1 + pow(tan(angle),2)) + tan(angle)*d ;
    return y;
}

int main() 
{
// test theta_c function
    double vel=450;
    double grav=9.8;
    double x=100;

    double thet=theta_c(vel,grav,x);
    cout << "Optimal Angle: " << thet << " radians" << endl;

// test rand_angle function
    double mean = 0;
    double stddev = 3*M_PI/180;
    double t = rand_angle(mean, stddev);
    cout << "Random Angle: " << t << " radians" << endl;

// teste high function
    double h = 0.7;
    double ang = thet + t;
    double yy = high(h, vel, grav, x, ang);
    cout << "theta  " << ang << " " << "high:  " << yy << "meters" << endl;


    double ttt=opt;
return 0;
}

