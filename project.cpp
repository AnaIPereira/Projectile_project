#include <iostream> 
#include <cmath>
#include <vector>
#include <fstream>
#include <random>
#include <unordered_map>

using namespace std;

// Function to compute histogram from a vector of data
std::unordered_map<double, int> computeHistogram(const std::vector<double>& data) {
    std::unordered_map<double, int> histogram;

    // Count occurrences of each unique element in the vector
    for (double value : data) {
        histogram[value]++;
    }

    return histogram;
}

class WritePyData {
public:
    string filename = "m_temp.txt";
    bool initialized = false;  // Added flag to track initialization

    WritePyData(const string& x, bool initialise = true) {
        filename = x;
        ofstream myfile;

        if (initialise && !initialized) {
            myfile.open(filename);
            myfile << "import numpy as np" << "\n" << "\n";
            myfile.close();
            initialized = true;
        }
    }

    void write_out_vector(const string& array_name, const vector<double>& array)
    {
        ofstream myfile;
        myfile.open(filename, std::ios_base::app);
        myfile << array_name << " = np.array((" << "\n";

        for (auto i = 0; i < array.size(); ++i) {
            if (i != (array.size() - 1)) {
                myfile << array.at(i) << ", " << "\n";
            } else {
                myfile << array.at(i) << "\n";
            }
        }
        myfile << "))" << "\n";
        myfile.close();
    }
};

// function to return optimal angle
double theta_c(double v0, double g, double d)
{
    double sr = 1 + 2*g/pow(v0,2)*(-0.6-1/2*g*pow(d,2)/pow(v0,2));
    double x = pow(v0,2)/(g*d)*(1 - sqrt(sr));
    double thetac = atan(x);
    return thetac;
}

// function to return angle from gaussian function
double rand_angle(double mean, double stddev) 
{
    random_device rd; 
    mt19937 gen(rd());
    normal_distribution<double> distribution(mean, stddev);
    return distribution(gen);
} 

// function to compute the high at which the bullet hits the target
double high(double h1, double v0, double g, double d, double angle)
{
    double y = h1 - 1/2*g*pow(d,2)/(pow(v0,2))*(1 + pow(tan(angle),2)) + tan(angle)*d ;
    return y;
}


// function that simulates 15 attemps as many times as we give in the argument
std::vector<double> numb_sim(double n)
 {
    // create vector that is going to save n attempts

    int tot = 15; // total number of attempts
    vector<double> vec_hits; // vector that saves # of hits
    double mean = 0;
    double stddev = 3 * M_PI / 180;
    double thet = theta_c(450, 9.8, 100); // computes the optimal angle

    for (int k = 0; k < n; k++) {
        //cout << "trial  " << k << endl;
        int hit = 0; // counter for the number of times that hit the target
        vector<double> position; // vector that saves position

        for (int i = 0; i < tot; i++) {
            double t = rand_angle(mean, stddev); // computes the random angle
            double angle = thet + t; // optimal angles plus random angle
            double yy = high(0.7, 450, 9.8, 100, angle); // computes the high
            position.push_back(yy); // vector that saves high for each attempt

            if (position[i] < 2.30 && position[i] > 0.30) {
                hit++; // in the end is the total number of hits
            }
        }
        vec_hits.push_back(hit); // saves the total number of hits for 15 attempt
    }

    cout << "vector size  " << vec_hits.size() << endl;
    //for (int p = 0; p < vec_hits.size(); p++)
   // {
       // cout << "number of hits  " << vec_hits[p] << endl;
   // }
    vector<double> hist_y(15);
    for (int l = 0; l < vec_hits.size(); l++)
    {
        for (int r = 0; r <= 15; r++)
            {
                if (vec_hits[l]==r)
                  {
                       hist_y[r]=hist_y[r]+1;
                  }
            }
    }
    for (int w = 0; w < hist_y.size(); w++)
    {
        cout << "yy hist  " << hist_y[w] << endl;
    }

    WritePyData dataWriter("m_temp.py"); // Create an instance of WritePyData

    // Use the instance to write data to the file
    dataWriter.write_out_vector("yy", vec_hits);
    return vec_hits;
}

// MAIN FUNCTION


int main() 
{
// test theta_c function
    double vel=450;
    double grav=9.8;
    double x=100;
    double thet=theta_c(vel,grav,x);
    //cout << "Optimal Angle: " << thet << " radians" << endl;

// test rand_angle function
    double mean = 0;
    double stddev = 3*M_PI/180;
    double t = rand_angle(mean, stddev);
    //cout << "Random Angle: " << t << " radians" << endl;

// teste high function
    double h = 0.7;
    double ang = thet + t;
    double yy = high(h, vel, grav, x, ang);
    //cout << "theta  " << ang << " " << "high:  " << yy << "meters" << endl;


std::vector<double> test = numb_sim(100);

//Histogram
std::unordered_map<double, int> histogram = computeHistogram(test);

std::cout << "Histogram:\n";
for (const auto& entry : histogram) {
    std::cout << entry.first << ": " << entry.second << " occurrences\n";
}


return 0;
}

