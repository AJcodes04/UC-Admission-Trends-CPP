/*
-------------------------------------------------------------------------------------------------------------------------------------------------------
The purpose of this header file is to read and parse data in the csv files

Class: CSVReader

Will include a constructor that takes in a string: filepath

a method to return a vector of parsed rows

additional helper methods
-------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#ifndef CSV_READER_H
#define CSV_READER_H

#include <string>
#include <vector>
#include <utility>

using namespace std;

class CSVReader
{
public:
    struct Record
    {
        string discipline;
        string school;
        string major;

        int applicants;
        int admits;
        int enrolls;
        int admitRate;
        int yieldRate;

        double admitGPA25, admitGPA75;
        double enrollGPA25, enrollGPA75;
    };

private:
    string filepath;

    static string trim(const string &s);
    static string removeQuotes(const string &s);
    static string removeCommas(const string &s); // For gpa

    static int parseInt(const string &s);
    static double parsePercent(const string &s);
    static pair<double, double> parseRange(const string &s);

    static vector<string> splitLine(const string &line);

public:
    explicit CSVReader(const string &fp);

    vector<vector<string>> readRawCSV() const;

    vector<Record> parseRecords() const;

    vector<string> getMajors() const;

    Record getRecordForMajor(const string &majorName) const;

    pair<double, double> getAdmitGPA(const string &majorName) const;
    pair<double, double> getEnrollGPA(const string &majorName) const;

    double getAdmitRate(const string &majorName) const;
    double getYieldRate(const string &majorName) const;

    int getApplicants(const string &majorName) const;
    int getAdmits(const string &majorName) const;
    int getEnrolls(const string &majorName) const;
};

#endif
