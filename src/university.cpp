#include "university.h"
#include "major.h"

#include <vector>
#include <string>

YearList::YearList(){
    head = nullptr;
}

YearList::~YearList() {
    freeList();
}

void YearList::freeList() {
    YearNode* curr = head;
    
    while(curr != nullptr){
        for(int i=0; i<curr->majors.size(); i++)
            delete curr->majors[i];

    YearNode* nextNode = curr->next;
    delete curr;
    curr = nextNode;
    }

    head = nullptr;

}

void YearList::addYear(int year) {
    if(head == nullptr){
        head == new YearNode(year);
        return;
    }

    YearNode* curr = head;

    while(curr->next != nullptr){
        if(curr->year == year)
            return;
        curr = curr->next;
    }

    if(curr->next->year == year)
        return;

    curr->next = new YearNode(year);
}

YearNode* YearList::findYear(int year) {
    YearNode* curr = head;

    while(curr != nullptr){
        if(curr->year == year)
            return curr;
        curr = curr->next;
    }

    return nullptr;
}

void YearList::addMajorToYear(int year, Major* major) {
    YearNode* node = findYear(year);

    if (node == nullptr) {
        addYear(year);
        node = findYear(year);  // now it must exist
    }

    for(int i=0; i<node->majors.size(); i++){
        if(node->majors[i]->majorName == major->majorName){
            return;
        }
    }

    node->majors.push_back(major);
}
