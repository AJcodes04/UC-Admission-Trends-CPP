/*
--------------------------------------------------------------------------------
CSVReader
Reads and parses a CSV file containing university admissions statistics.

This class is responsible only for:
    • Opening a CSV file
    • Reading each line into exactly 10 data fields
    • Splitting based on commas (while preserving commas inside major names)
    • Looping through each field (0–9) and calling a dedicated parser function
      such as:
          parseBroadDiscipline()
          parseCollegeSchool()
          parseMajorName()
          parseApplicants()
          parseAdmits()
          parseEnrolls()
          parseAdmitGPA()
          parseEnrollGPA()
          parseAdmitRate()
          parseYieldRate()

Design:
    - Because each CSV line always contains the same number of columns, parsing
      is handled with a single for-loop:
          
          for (int i = 0; i < NUM_FIELDS; i++) {
              switch(i) {
                  case 0: major->broadDiscipline = parseBroadDiscipline(fields[i]); break;
                  ...
              }
          }

    - Each field has its own parsing helper to keep responsibilities separate
      and maintain clean, readable logic.

    - After constructing a fully populated Major object, the reader inserts it
      into the appropriate:
          Database → School → YearList → YearNode → majors vector

Responsibilities:
    - File reading
    - Line splitting
    - Field-by-field parsing
    - Passing parsed data into the Database

Non-Responsibilities:
    - Storing data long-term
    - Memory ownership of schools, years, or majors
    - Displaying or analyzing data

CSVReader acts purely as a parser and data loader.

--------------------------------------------------------------------------------
*/



#ifndef CSV_READER_H
#define CSV_READER_H

#include <string>
#include <vector>
#include "database.h"

class CSVReader {
public:
    CSVReader(const std::string& filename);

    // Parse entire CSV into the database for a given year
    void parse(Database& db, int year);

private:
    std::string filename;

    // Splitting & cleaning
    std::vector<std::string> splitLine(const std::string& line);
    std::string trim(const std::string& s);

    // Numeric parsing helpers
    std::string parseQuote(const std::string& s);
    int parsePercent(const std::string& s);

    // Parse each field by index (0–10)
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

    int cursor;
};

#endif
