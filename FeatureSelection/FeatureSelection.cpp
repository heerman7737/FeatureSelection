// FeatureSelection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <limits>
#include <iomanip>
#include <numeric>
using namespace std;



void printdatadouble(const vector<double> d) {
    for (int i = 0; i < d.size(); ++i) {
        cout << d[i]<<" ";
    }
    cout << "\n";
}
void printdataint(const vector<int>& d) {
    for (int i = 0; i < d.size(); ++i) {
        cout << d[i] << " ";
    }
    cout << "\n";
}
vector<double> sfeature(const vector<double>& singledata,const vector<int>& set) {
    vector<double> result;
    for (int i = 0; i < set.size();++i) {
        result.push_back(singledata[set[i]]);
    }
    return result;
}
double distance(const vector<double>& f1, const vector<double>& f2) {
    double sum = 0.0;
    //cout << f1.size();
    for (int i = 0; i < f1.size(); ++i) {
        sum += pow((f1[i] - f2[i]),2);
    }
    return sqrt(sum);
}
double accuracy(const vector<vector<double>>& data,const vector<int>& curr_set,int added) {
    int correct = 0;
    double result;
    vector<int> temp_set = curr_set;
    vector<double> feature1;
    vector<double> feature2;
    double dist;
    int len = data.size();
    int nnlable = 0;
    temp_set.push_back(added);
    for (int i = 0; i <len ; ++i) {
        int label = data[i][0];
        for (int j = 0; j < temp_set.size(); ++j) {
            feature1.push_back(data[i][temp_set[j]]);
        }
        //cresult.clear();
        //cout << data[i].size();
        //cout << "Feature 1:";
        //printdatadouble(feature1);
    
        double nnd = 99999999;
        int nnl;
        double sum;
        for (int k = 0; k < len; ++k) {
            
            if (i != k) {
                for (int j = 0; j < temp_set.size(); ++j) {
                    feature2.push_back(data[k][temp_set[j]]);
                }
                sum = 0.0;
                //cresult.clear();
                for (int i = 0; i < feature1.size(); ++i) {
                    sum += pow((feature1[i] - feature2[i]),2);
                }
                dist = sqrt(sum);
                feature2.clear();
                //cout << "Feature 2:";
                //printdatadouble(feature2);
                //cout << "Dist: "<<k<<" is " << dist<<"\n";
                if (dist < nnd) {
                    //cout << "Run "<<dist<<"\n";
                    nnd = dist;
                    nnl = k;
                    nnlable = data[nnl][0];
                    //cout << nnlable<<"\n";
                }
            }
            
        }
        feature1.clear();
        if (label == nnlable) {
            correct = correct + 1;
            //cout << correct << "\n";
        }
        
    }
    result = (double)correct/ len;
    cout << result<<"\n";
    return result;
}
void search(const vector<vector<double>>& data) {

    vector<int> features;
    vector<int> best_set;
    double best_accuracy = 0;
    double temp;
    int feature_to_add = 0;
    //cout << data[0].size();
    for (int i = 1; i < data[0].size(); ++i) {
        
        cout << "On the " << i << "th level of the search tree" << "\n";
        double curr_accuracy = 0;
        for (int k = 1; k < data[0].size(); ++k) {
            if (find(features.begin(), features.end(), k) == features.end()) {
                cout << "--Considering adding feature " << k << "\n";
                
                temp = accuracy(data, features, k);
                if (temp > curr_accuracy) {
                    curr_accuracy = temp;
                    feature_to_add = k;
                }
            }
        }
        cout << "On level " << i << " added feature " << feature_to_add << "\n";
        features.push_back(feature_to_add);
        if (curr_accuracy > best_accuracy) {
            best_set = features;
            best_accuracy = curr_accuracy;
        }
        printdataint(features);
    }
    cout << "Finish search! The best feature subset is ";
    printdataint(best_set);
    cout << "Best accuracy: " << 100 * best_accuracy << "%";
}
double daccuracy(const vector<vector<double>>& data, const vector<int>& curr_set, int added) {
    int correct = 0;
    double result;
    vector<int> temp_set = curr_set;
    vector<double> feature1;
    vector<double> feature2;
    double dist;
    int len = data.size();
    int nnlable = 0;
    temp_set.erase(remove(temp_set.begin(), temp_set.end(), added), temp_set.end());
    for (int i = 0; i < len; ++i) {
        int label = data[i][0];
        for (int j = 0; j < temp_set.size(); ++j) {
            feature1.push_back(data[i][temp_set[j]]);
        }
        //cresult.clear();
        //cout << data[i].size();
        //cout << "Feature 1:";
        //printdatadouble(feature1);

        double nnd = 99999999;
        int nnl;
        double sum;
        for (int k = 0; k < len; ++k) {

            if (i != k) {
                for (int j = 0; j < temp_set.size(); ++j) {
                    feature2.push_back(data[k][temp_set[j]]);
                }
                sum = 0.0;
                //cresult.clear();
                for (int i = 0; i < feature1.size(); ++i) {
                    sum += pow((feature1[i] - feature2[i]), 2);
                }
                dist = sqrt(sum);
                feature2.clear();
                //cout << "Feature 2:";
                //printdatadouble(feature2);
                //cout << "Dist: "<<k<<" is " << dist<<"\n";
                if (dist < nnd) {
                    //cout << "Run "<<dist<<"\n";
                    nnd = dist;
                    nnl = k;
                    nnlable = data[nnl][0];
                    //cout << nnlable<<"\n";
                }
            }

        }
        feature1.clear();
        if (label == nnlable) {
            correct = correct + 1;
            //cout << correct << "\n";
        }

    }
    result = (double)correct / len;
    cout << result << "\n";
    return result;
}
void back(const vector<vector<double>>& data) {

    vector<int> features(data[0].size()-1);
    //vector<int> features = { 17,18,19,20,21,22,23,24,25,26,27 };
    std::iota(features.begin(), features.end(), 1);
    vector<int> best_set(data[0].size()-1);
    std::iota(features.begin(), features.end(), 1);
    //vector<int> best_set = { 17,18,19,20,21,22,23,24,25,26,27 };
    double best_accuracy = 0;
    double temp;
    int feature_to_add;
    //cout << data[0].size();
    for (int i = 1; i < data[0].size(); ++i) {

        cout << "On the " << i << "th level of the search tree" << "\n";
        double curr_accuracy = 0;
        for (int k = 1; k < data[0].size(); ++k) {
            if (find(features.begin(), features.end(), k) != features.end()) {
                cout << "--Considering eliminating feature " << k << "\n";

                temp = daccuracy(data, features, k);
                if (temp >= curr_accuracy) {
                    curr_accuracy = temp;
                    feature_to_add = k;
                }
            }
        }
        cout << "On level " << i << " eliminated feature " << feature_to_add << "\n";
        features.erase(remove(features.begin(), features.end(), feature_to_add), features.end());
        if (curr_accuracy > best_accuracy) {
            best_set = features;
            best_accuracy = curr_accuracy;
        }
        printdataint(features);
    }
    cout << "Finish search! The best feature subset is ";
    printdataint(best_set);
    cout << "Best accuracy: " << 100 * best_accuracy << "%";
}
int main()
{
    string mytext;
    string filename;
    cout << "Welcome to Giang KNN\n";
    cout << "Type file name:\n";
    cin >> filename;
    vector<vector<double>>* data = new vector<vector<double>>;
    //vector<vector<double>>& data = *dr;
    double temps;
    
    ifstream myfile(filename);

    cout << mytext;
    int i = 0;
    while (getline(myfile, mytext)) {
        istringstream num(mytext);

        (*data).push_back(vector<double>());
        while (num >> temps) {
            (*data)[i].push_back(temps);
        }
        i++;
    }
    //cout << (*data)[499][10];
    int algorithm;
    cout << "Choose algorithm, 1 for Forward Selection, 2 for Backward Elimination\n";
    cin >> algorithm;
    vector<vector<double>>& dr = *data;
    //for (int c = 0; c < 500; c++) {
    //    printdatadouble(dr[c]);
    //}
    if (algorithm == 1) {
        search(dr);
    }
    else {
        back(dr);
    }
    myfile.close();


    //vector<int> fset = {  };
    //accuracy(dr,fset,1,data->size());

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
