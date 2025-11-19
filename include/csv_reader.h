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
#include <fstream>
#include <sstream>

class CSVReader
{
public:
    struct Record
    {
        std::string discipline;
        std::string school;
        std::string major;

        int applicants;
        int admits;
        int enrolls;
        int admitRate;
        int yieldRate;

        double admitGPA25, admitGPA75;
        double enrollGPA25, enrollGPA75;
    };

private:
    std::string filepath;

    static std::string trim(const std::string &s);
    static std::string removeQuotes(const std::string &s);
    static std::string removeCommas(const std::string &s);

    static int parseInt(const std::string &s);
    static int parsePercent(const std::string &s);
    static std::pair<double, double> parseRange(const std::string &s);

    static std::vector<std::string> splitLine(const std::string &line);

public:
    explicit CSVReader(const std::string &fp);

    std::vector<std::vector<std::string>> readRawCSV() const;

    std::vector<Record> parseRecords() const;

    const std::vector<std::string> &getMajors() const;

    Record getRecordForMajor(const std::string &majorName) const;

    std::pair<double, double> getAdmitGPA(const std::string &majorName) const;
    std::pair<double, double> getEnrollGPA(const std::string &majorName) const;

    int getAdmitRate(const std::string &majorName) const;
    int getYieldRate(const std::string &majorName) const;

    int getApplicants(const std::string &majorName) const;
    int getAdmits(const std::string &majorName) const;
    int getEnrolls(const std::string &majorName) const;
};

#endif
