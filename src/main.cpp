#include <iostream>
#include <string>
#include <vector>

#include "../include/csv_reader.h"
#include "../include/database.h"
#include "../include/university.h"
#include "../include/major.h"


int main()
{

    Database db;

    for (int i = 2012; i <= 2023; i++) {

        std::string filename = "../data/csv_exports/UCB-" + std::to_string(i) + ".csv";
        CSVReader readerUCB(filename);
        readerUCB.parse(db, i, "UCB");

        filename = "../data/csv_exports/UCLA-" + std::to_string(i) + ".csv";
        CSVReader readerUCLA(filename);
        readerUCLA.parse(db, i, "UCLA");

        filename = "../data/csv_exports/UCSD-" + std::to_string(i) + ".csv";
        CSVReader readerUCSD(filename);
        readerUCSD.parse(db, i, "UCSD");

        filename = "../data/csv_exports/UCI-" + std::to_string(i) + ".csv";
        CSVReader readerUCI(filename);
        readerUCI.parse(db, i, "UCI");

        filename = "../data/csv_exports/UCSB-" + std::to_string(i) + ".csv";
        CSVReader readerUCSB(filename);
        readerUCSB.parse(db, i, "UCSB");

        filename = "../data/csv_exports/UCD-" + std::to_string(i) + ".csv";
        CSVReader readerUCD(filename);
        readerUCD.parse(db, i, "UCD");

        filename = "../data/csv_exports/UCR-" + std::to_string(i) + ".csv";
        CSVReader readerUCR(filename);
        readerUCR.parse(db, i, "UCR");

        filename = "../data/csv_exports/UCSC-" + std::to_string(i) + ".csv";
        CSVReader readerUCSC(filename);
        readerUCSC.parse(db, i, "UCSC");

        filename = "../data/csv_exports/UCM-" + std::to_string(i) + ".csv";
        CSVReader readerUCM(filename);
        readerUCM.parse(db, i, "UCM");
    }

    bool goAgain = true;

    while (goAgain){

        std::string userSchool;
        int userYear;
        std::string userMajor;

        std::cout << "Enter school name (example: UCSD): ";
        std::getline(std::cin, userSchool);

        std::cout << "Enter year: ";
        std::cin >> userYear;
        std::cin.ignore();

        std::cout << "Enter major name exactly as in CSV: ";
        std::getline(std::cin, userMajor);

        School* s = db.getSchool(userSchool);

        YearNode* node = s->years->findYear(userYear);

        Major* target = nullptr;
        for (Major* m : node->majors) {
            if (m->majorName == userMajor) {
                target = m;
                break;
            }
        }

        if (!target) {
            std::cout << "Major not found.\n";
            return 0;
        }

        std::cout << "\n=== Admission Statistics ===\n";
        std::cout << "School: " << userSchool << "\n";
        std::cout << "Year:   " << userYear << "\n";
        std::cout << "Major:  " << userMajor << "\n\n";

        std::cout << "Applicants:    " << target->applicants << "\n";
        std::cout << "Admits:        " << target->admits << "\n";
        std::cout << "Enrolls:       " << target->enrolls << "\n";
        std::cout << "Admit GPA:     " << target->admitGPARange << "\n";
        std::cout << "Enroll GPA:    " << target->enrollGPARange << "\n";
        std::cout << "Admit Rate:    " << target->admitRate << "\n";
        std::cout << "Yield Rate:    " << target->yieldRate << "\n\n";

        return 0;

    }

}