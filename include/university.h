/*
-------------------------------------------------------------------------------------------------------------------------------------------------------
Represents a single university / model

Class: University
private: name, head of linkedlist
The nodes will include a struct or small class for YearlyData for admitGPA, acceptanceRate, # of applicants etc.

public methods for
printing out
fetching new data
calculating averages or trends maybe

include destructors to free up memory



features:
ask user which university data they would like to see
prompt them about the data they would like to view
then display the data they chose


-------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>
#include <vector>
using namespace std;

class University
{
private:
    string university_name;
    struct YearlyData
    {
        int year;
        int admitRate;
        int applicants;
        int admits;
        int enrolls;

        double enrollGPA;
        double admitGPA25, admitGPA75;

        string major;
        string college;
        string discipline;
    };

    struct Node
    {
        YearlyData data;
        Node *next;
    };
    Node *head;

public:
    University(string name);

    void printYearData(int year);
    void printAllYears();

    YearlyData getLatestYear() const;
    YearlyData getYearData(int year) const;
    vector<YearlyData> getAllYearData() const;
};

#endif