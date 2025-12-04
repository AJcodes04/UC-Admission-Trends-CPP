#ifndef CSV_READER_H
#define CSV_READER_H

#include <string>

class Database;

class CSVReader {
public:
    CSVReader(const std::string& filename);

    void parse(Database& db, int year, std::string university);

private:
    std::string filename;
    int cursor;

    // Helper functions you use in csv_reader.cpp
    std::string parseQuote(const std::string& s);
    int parsePercent(const std::string& s);

    std::string parseBroadDiscipline(const std::string& s);
    std::string parseCollegeSchool(const std::string& s);
    std::string parseMajorName(const std::string& s);
    std::string parseApplicants(const std::string& s);
    std::string parseAdmits(const std::string& s);
    std::string parseEnrolls(const std::string& s);
    std::string parseAdmitGPA(const std::string& s);
    std::string parseEnrollGPA(const std::string& s);
    std::string parseAdmitRate(const std::string& s);
    std::string parseYieldRate(const std::string& s);
};

#endif
