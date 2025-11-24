#include "csv_reader.h"
#include "database.h"
#include "major.h"
#include "university.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

CSVReader::CSVReader(const std::string& filename)
    : filename(filename) {}

void CSVReader::parse(Database& db, int year) {

}

std::vector<std::string> CSVReader::splitLine(const std::string& line) {
    return {};
}

std::string CSVReader::trim(const std::string& s) {
    return "";
}

int CSVReader::parseInt(const std::string& s) {
    return 0;
}

int CSVReader::parsePercent(const std::string& s) {
    return 0;
}

// Field-specific parsing ------------------------------------

std::string CSVReader::parseBroadDiscipline(const std::string& s) {
    return "";
}

std::string CSVReader::parseCollegeSchool(const std::string& s) {
    return "";
}

std::string CSVReader::parseMajorName(const std::string& s) {
    return "";
}

int CSVReader::parseApplicants(const std::string& s) {
    return 0;
}

int CSVReader::parseAdmits(const std::string& s) {
    return 0;
}

int CSVReader::parseEnrolls(const std::string& s) {
    return 0;
}

std::string CSVReader::parseAdmitGPA(const std::string& s) {
    return "";
}

std::string CSVReader::parseEnrollGPA(const std::string& s) {
    return "";
}

int CSVReader::parseAdmitRate(const std::string& s) {
    return 0;
}

int CSVReader::parseYieldRate(const std::string& s) {
    return 0;
}
