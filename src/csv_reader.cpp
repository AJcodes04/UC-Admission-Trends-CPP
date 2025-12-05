#include "../include/csv_reader.h"
#include "../include/database.h"
#include "../include/major.h"
#include "../include/university.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

CSVReader::CSVReader(const std::string& filename) : filename(filename) {}

void CSVReader::parse(Database& db, int year, std::string university) {
    std::ifstream currentfile(filename);

    if (currentfile.fail()) {
        std::cout << "Couldn't open file" << filename << std::endl;
        return;
    }

    std::string header;
    std::getline(currentfile, header);

    std::string line;

    while (std::getline(currentfile, line)) {
        cursor = 0;
        Major* m = new Major;

        m->universityName = university;
        for (int i = 0; i < 10; i++) {
            if (i == 0) {
                m->broadDiscipline = parseBroadDiscipline(line);
            }
            if (i == 1) {
                m->college = parseCollegeSchool(line);
            }
            if (i == 2) {
                m->majorName = parseMajorName(line);
            }
            if (i == 3) {
                m->applicants = parseApplicants(line);
            }
            if (i == 4) {
                m->admits = parseAdmits(line);
            }
            if (i == 5) {
                m->enrolls = parseEnrolls(line);
            }
            if (i == 6) {
                m->admitGPARange = parseAdmitGPA(line);
            }
            if (i == 7) {
                m->enrollGPARange = parseEnrollGPA(line);
            }
            if (i == 8) {
                m->admitRate = parseAdmitRate(line);
            }
            if (i == 9) {
                m->yieldRate = parseYieldRate(line);
            }
        }

        db.insertMajor(m->universityName, year, m);

    }
}

std::string CSVReader::parseQuote(const std::string& s) {
    std::string field = "";
    int count = 1;
    bool a = true;

    while (a) {
        if (s[count] == ',')
            count++;
        else if (s[count] == '\"')
            a = false;
        else {
            field.push_back(s[count]);
            count++;
        }
    }

    return field;
}

int CSVReader::parsePercent(const std::string& s) {
    return 0;
}

std::string CSVReader::parseBroadDiscipline(const std::string& s) {
    std::string field = "";

    while (cursor < s.size() && s[cursor] != ',') {
        cursor++;
        field.push_back(s[cursor]);
    }
    cursor++;
    return field;
}

std::string CSVReader::parseCollegeSchool(const std::string& s) {
    std::string field = "";

    while (cursor < s.size() && s[cursor] != ',') {
        field.push_back(s[cursor]);
        cursor++;
    }
    cursor++;
    return field;
}

std::string CSVReader::parseMajorName(const std::string& s) {
    std::string field = "";
    int quoteCount = 0;

    if (s[cursor] == '\"') {
        while (cursor < s.size() && quoteCount<2) {
            field.push_back(s[cursor]);
            cursor++;
            if (s[cursor] == '\"')
                quoteCount++;
        }
        cursor += 2;
        field = parseQuote(field);
    }
    else {
        while (cursor < s.size() && s[cursor] != ',') {
            field.push_back(s[cursor]);
            cursor++;
        }
    }

    cursor++;
    return field;
}

std::string CSVReader::parseApplicants(const std::string& s) {
    std::string field = "";
    int commaCount = 0;

    if (s[cursor] == '\"') {
        while (cursor < s.size() && commaCount < 2) {
            field.push_back(s[cursor]);
            cursor++;
            if (s[cursor] == ',')
                commaCount++;
        }
        field = parseQuote(field);
    }
    else {
        while (cursor < s.size() && s[cursor] != ',') {
            field.push_back(s[cursor]);
            cursor++;
        }
    }

    cursor++;
    return field;
}

std::string CSVReader::parseAdmits(const std::string& s) {
    std::string field = "";
    int commaCount = 0;

    if (s[cursor] == '\"') {
        while (cursor < s.size() && commaCount < 2) {
            field.push_back(s[cursor]);
            cursor++;
            if (s[cursor] == ',')
                commaCount++;
        }
        field = parseQuote(field);
    }
    else {
        while (cursor < s.size() && s[cursor] != ',') {
            field.push_back(s[cursor]);
            cursor++;
        }
    }

    cursor++;
    return field;
}

std::string CSVReader::parseEnrolls(const std::string& s) {
    std::string field = "";
    int commaCount = 0;

    if (s[cursor] == '\"') {
        while (cursor < s.size() && commaCount < 2) {
            field.push_back(s[cursor]);
            cursor++;
            if (s[cursor] == ',')
                commaCount++;
        }
        field = parseQuote(field);
    }
    else {
        while (cursor < s.size() && s[cursor] != ',') {
            field.push_back(s[cursor]);
            cursor++;
        }
    }

    cursor++;
    return field;
}

std::string CSVReader::parseAdmitGPA(const std::string& s) {
    std::string field = "";

    while (cursor < s.size() && s[cursor] != ',') {
        field.push_back(s[cursor]);
        cursor++;
    }

    if (s[cursor + 1] == ' ') {
        field.push_back(',');
        cursor++;
        while (cursor < s.size() && s[cursor] != ',') {
            field.push_back(s[cursor]);
            cursor++;
        }
    }

    cursor++;
    return field;
}

std::string CSVReader::parseEnrollGPA(const std::string& s) {
    std::string field = "";

    while (cursor < s.size() && s[cursor] != ',') {
        field.push_back(s[cursor]);
        cursor++;
    }

    if (s[cursor + 1] == ' ') {
        field.push_back(',');
        cursor++;
        while (cursor < s.size() && s[cursor] != ',') {
            field.push_back(s[cursor]);
            cursor++;
        }
    }

    cursor++;
    return field;
}

std::string CSVReader::parseAdmitRate(const std::string& s) {
    std::string field = "";

    while (cursor < s.size() && s[cursor] != ',') {
        field.push_back(s[cursor]);
        cursor++;
    }

    if (s[cursor + 1] == ' ') {
        field.push_back(',');
        cursor++;
        while (cursor < s.size() && s[cursor] != ',') {
            field.push_back(s[cursor]);
            cursor++;
        }
    }

    cursor++;
    return field;
}

std::string CSVReader::parseYieldRate(const std::string& s) {
    std::string field = "";

    while (cursor < s.size() && s[cursor] != ',') {
        field.push_back(s[cursor]);
        cursor++;
    }

    if (s[cursor + 1] == ' ') {
        field.push_back(',');
        cursor++;
        while (cursor < s.size() && s[cursor] != ',') {
            field.push_back(s[cursor]);
            cursor++;
        }
    }

    cursor++;
    return field;
}
