// FeatureSelection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<double> sfeature() {

}
double distance() {
    return 0.0;
}
double accuracy(vector<vector<double>> data,vector<int> curr_set,int added) {
    int correct = 0;
    vector<int> temp_set = curr_set;
    vector<double> feature1;
    temp_set.push_back(added);
    for (int i = 0; i < data.size(); i++) {
        int label = data[i][0];
        feature1 = sfeature();
    }
    return correct / data.size();
}
void search(vector<vector<double>> data) {
    vector<int> features;
    vector<int> best_set;
    double best_accuracy = 0;
    //cout << data[0].size();
    for (int i = 1; i < data[0].size(); i++) {
        for (int k = 1; k < data[0].size(); k++) {
            
        }
    }
}
int main()
{
    string mytext;
    vector<vector<double>> data;
    double temp;
    ifstream myfile("Ver_2_CS170_Fall_2021_Small_data__86.txt");
    
    cout << mytext;
    int i = 0;
    while (getline(myfile, mytext)) {
        istringstream num(mytext);
        
        data.push_back(vector<double>());
        while (num >> temp) {
             data[i].push_back(temp);
        }
        i++;
    }
    //cout << data[499][1];
    
    myfile.close();
    //search(data);
    vector<int> fset;
    accuracy(data,fset,1);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
