#include <iostream> 
#include <cmath>
#include <vector>
#include <fstream>
#include <random>
#include <unordered_map>

using namespace std;

// Function to compute histogram from a vector of data
std::unordered_map<double, int> computeHistogram(const std::vector<double>& data) 
{
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
double theta_c(double v0, double g, double d, double h1, double h2)
{
    double sr = 1 + 2*g/pow(v0,2)*(h1-h2-1/2*g*pow(d,2)/pow(v0,2));
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


// function that simulates tot attemps as many times as we give in the argument and simulate it n times
std::vector<double> numb_sim(double n, int tot, double stddev, double thet, double y_init, double vel, double dist)
 {
    // create vector that is going to save n attempts
    vector<double> vec_hits; // vector that saves # of hits
    vector<double> save_thet; // vector that saves thetas in each tria
    double mean = 0;

    for (int k = 0; k < n; k++) {
        //cout << "trial  " << k << endl;
        int hit = 0; // counter for the number of times that hit the target
        vector<double> position; // vector that saves position

        for (int i = 0; i < tot; i++) {
            double t = rand_angle(mean, stddev); // computes the random angle
            double angle = thet + t; // optimal angles plus random angle
            save_thet.push_back(angle);
            double yy = high(y_init, vel, 9.8, dist, angle); // computes the high
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

    double theta_med = 0;
    for (int u = 0; u < save_thet.size(); u++)
    {
        theta_med = theta_med + save_thet[u];
    }

    double theta_med_fin = theta_med/(n*tot);
        cout << "mean " << theta_med_fin << endl;

    double variance;
    for (int l = 0; l < save_thet.size(); l++)
    {
        variance = variance + pow((save_thet[l]-theta_med),2);
    }
    double variance_fin = variance /(n*tot);
    cout << "variance " << variance_fin << endl;
    return vec_hits;
}

// MAIN FUNCTION


int main() 
{
    double thet1 = theta_c(450, 9.8, 100, 0.7, 1.3); // computes the optimal angle for shooter 1
    cout << "Optimal Angle 1: " << thet1 << " radians" << endl;
    double thet2 = theta_c(600, 9.8, 100, 0.3, 1.3); // computes the optimal angle for shooter 2
    cout << "Optimal Angle 2: " << thet2 << " radians" << endl;

std::vector<double> test1 = numb_sim(100, 15, 3 * M_PI / 180, thet1, 0.7, 450, 100);
std::vector<double> test2 = numb_sim(1000, 15, 3 * M_PI / 180, thet1, 0.7, 450, 100);
std::vector<double> test3 = numb_sim(10000, 15, 3 * M_PI / 180, thet1, 0.7, 450, 100);

std::vector<double> test4 = numb_sim(100, 10, 1 * M_PI / 180, thet2, 0.3, 600, 100);
std::vector<double> test5 = numb_sim(1000, 10, 1 * M_PI / 180, thet2, 0.3, 600, 100);
std::vector<double> test6 = numb_sim(10000, 10, 1 * M_PI / 180, thet2, 0.3, 600, 100);

// Histograms
std::unordered_map<double, int> histogram1 = computeHistogram(test1);
std::unordered_map<double, int> histogram2 = computeHistogram(test2);
std::unordered_map<double, int> histogram3 = computeHistogram(test3);

std::unordered_map<double, int> histogram4 = computeHistogram(test4);
std::unordered_map<double, int> histogram5 = computeHistogram(test5);
std::unordered_map<double, int> histogram6 = computeHistogram(test6);

// Print histograms
std::cout << "Histogram for test1:\n";
for (const auto& entry : histogram1) {
    std::cout << entry.first << ": " << entry.second << " occurrences\n";
}

std::cout << "Histogram for test2:\n";
for (const auto& entry : histogram2) {
    std::cout << entry.first << ": " << entry.second << " occurrences\n";
}

std::cout << "Histogram for test3:\n";
for (const auto& entry : histogram3) {
    std::cout << entry.first << ": " << entry.second << " occurrences\n";
}

std::cout << "Histogram for test4:\n";
for (const auto& entry : histogram4) {
    std::cout << entry.first << ": " << entry.second << " occurrences\n";
}

std::cout << "Histogram for test5:\n";
for (const auto& entry : histogram5) {
    std::cout << entry.first << ": " << entry.second << " occurrences\n";
}

std::cout << "Histogram for test6:\n";
for (const auto& entry : histogram6) {
    std::cout << entry.first << ": " << entry.second << " occurrences\n";
}

WritePyData dataWriter1("m_temp1.py");
dataWriter1.write_out_vector("yy1", test1);

WritePyData dataWriter2("m_temp2.py");
dataWriter2.write_out_vector("yy2", test2);

WritePyData dataWriter3("m_temp3.py");
dataWriter3.write_out_vector("yy3", test3);

WritePyData dataWriter4("m_temp4.py");
dataWriter4.write_out_vector("yy4", test4);

WritePyData dataWriter5("m_temp5.py");
dataWriter5.write_out_vector("yy5", test5);

WritePyData dataWriter6("m_temp6.py");
dataWriter6.write_out_vector("yy6", test6);


return 0;
}

