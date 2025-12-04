#include "../include/database.h"
#include "../include/university.h"
#include "../include/major.h"

#include <string>
#include <vector>

void Database::addSchool(const std::string& name) {
    for(int i = 0; i<schools.size(); i++){
        School* s = schools[i];
        if(s->name == name){
            return;
        }
    }
    School *s = new School(name);
    schools.push_back(s);
}

School* Database::getSchool(const std::string& name) {
    for(int i = 0; i<schools.size(); i++){
        School* s = schools[i];
        if(s->name==name)
            return(s);
    }

    return nullptr;
}

void Database::insertMajor(const std::string& schoolName, int year, Major* major) {
    School* s = getSchool(schoolName);

    if(!s){
        addSchool(schoolName);
        s = getSchool(schoolName);
    }

    s->years->addMajorToYear(year, major);
}
