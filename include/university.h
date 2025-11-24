/*
--------------------------------------------------------------------------------
Defines the University model, which stores a linked list of yearly data.

Components:
1. YearNode (struct)
   - Represents a single year (e.g., 2020).
   - Contains:
        • Year value
        • Vector of Major* objects for that year's majors
        • Pointer to next YearNode (linked list)

2. YearList (class)
   - Manages a singly linked list of YearNode objects.
   - Provides:
        • addYear(int)
        • findYear(int)
        • addMajorToYear(int year, Major* m)
   - Includes destructor logic to free YearNode list and Major* pointers.

3. School (struct)
   - Represents a single university/school (e.g., UCSD).
   - Contains:
        • Name of the school
        • Pointer to a YearList object
   - Owns its YearList and frees it in the destructor.

Notes:
- This file models how a university’s admission data evolves over years.
- Memory ownership is handled explicitly: YearList frees nodes; School frees YearList.
--------------------------------------------------------------------------------
*/


#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>
#include <vector>
#include "major.h"

struct YearNode {
    int year;                       // e.g., 2020
    std::vector<Major*> majors;     // all majors for this year
    YearNode* next;

    YearNode(int y) : year(y), next(nullptr) {}
};

class YearList {
public:
    YearList();
    ~YearList();

    void addYear(int year);
    YearNode* findYear(int year);
    void addMajorToYear(int year, Major* major);

private:
    YearNode* head;
    void freeList();
};

struct School {
    std::string name;
    YearList* years;

    School(const std::string& s) {
        name = s;
        years = new YearList();
    }

    ~School() {
        delete years;
    }
};

#endif