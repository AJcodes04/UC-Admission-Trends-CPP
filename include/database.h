/*
--------------------------------------------------------------------------------
Top-level container holding all universities/schools in the project.

Class: Database
- Stores a vector<School*>.
- Provides methods to:
    • addSchool(name)
    • search for a School by name
    • insert a Major into the correct school + year (creates year if missing)

Responsibilities:
- Acts as the root of the entire data structure.
- Controls creation and lookup of School objects.
- Coordinates insertion of data parsed from CSVReader.

Memory:
- Owns all School* objects; destructor should free them.
--------------------------------------------------------------------------------
*/


#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include "university.h"

class Database {
public:
    void addSchool(const std::string& name);
    School* getSchool(const std::string& name);

    void insertMajor(const std::string& schoolName, int year, Major* major);

    const std::vector<School*>& getSchools() const { return schools; }

private:
    std::vector<School*> schools;
};

#endif
