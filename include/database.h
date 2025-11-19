/*
-------------------------------------------------------------------------------------------------------------------------------------------------------
The purpose of this header file is to manage and keep track of multiple universities and allow you to query data

Class: Database
stores all the universities in a vector

methods for:
looking up a university by name
comparing data from other universities
print summaries

other helper functions

-------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include "university.h"

class Database
{
private:
    std::vector<University> universities;
    bool containsUniversity(const std::string &name) const;
    bool validInput(const std::string &userInput) const;
    void sortUniversitiesByGPA();

public:
    void printAllNames() const;
    void printAllUniversityStats() const;
    void compareTwoUniversities(const std::string &universityOne, const std::string &universityTwo) const;
    void filterByMajorGPA(const std::string &major, double GPA) const;

    // return type, the university object
    const University *getUniversity(const std::string &universityName) const;
    std::vector<std::string> getAllUniversityNames() const;
    const std::vector<University> &getAllUniversities() const;
};

#endif