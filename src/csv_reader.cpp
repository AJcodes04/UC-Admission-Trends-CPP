#ifndef CSV_READER_H
#define CSV_READER_H

#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>

class CSVReader{
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

    std::string CSVReader::trim(const std::string &s){
        int start = 0;
        int end = s.length() - 1;

        while(start<=end && (s[start]==' ' || s[start]=='\t' || s[start]=='\n' || s[start]=='\r'))
            start++;
        
        while(end>=start && (s[end]==' ' || s[end]=='\t' || s[end]=='\n' || s[end]=='\r'))
            end--;
        
        std::string result;

        for(int i = start; i<=end; i++)
            result += s[i];
        
        return result;
    }
    std::string CSVReader::removeQuotes(const std::string &s){
        int start = 0;
        int end = s.length() - 1;

        if(end>=1 && ((s[start] == '"' && s[end] == '"')||(s[start] == '\'' && s[end] == '\''))){
            return s.substr(1, end-1);
        }

        return s;
    }
    std::string CSVReader::removeCommas(const std::string &s){
        int start = 0;
        int end = s.length() - 1;
        std::string result = "";
        for(int i = 0; i<=s.length()-1; i++){
            if(s[i] != ',')
                result += s[i];
        }
        return result;
    }

    int CSVReader::parseWord(const std::string &s){
        int result;

        for(int i=0; i<=s.length()-1; i++){
            
        }
    }
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
