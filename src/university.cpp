#include "university.h"
#include "major.h"

#include <vector>
#include <string>

// -------------------
// YearList Management
// -------------------

YearList::YearList()
    : head(nullptr) {}

// Free the linked list
YearList::~YearList() {
}

void YearList::freeList() {
}

void YearList::addYear(int year) {
}

YearNode* YearList::findYear(int year) {
    return nullptr;
}

void YearList::addMajorToYear(int year, Major* major) {
}


School::~School() {
}
