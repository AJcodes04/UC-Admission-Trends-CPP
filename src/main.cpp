#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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

        std::cout <<
        "\nEnter school name:\n"
        "  - UCB\n"
        "  - UCLA\n"
        "  - UCSD\n"
        "  - UCI\n"
        "  - UCSB\n"
        "  - UCD\n"
        "  - UCSC\n"
        "  - UCR\n"
        "  - UCM\n\n"
        "Your choice: ";
        std::getline(std::cin, userSchool);

        std::cout << "\nEnter year: ";
        std::cin >> userYear;
        std::cin.ignore();

        std::cout << "\nEnter major name exactly as in CSV: ";
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

    const int LABEL_W = 20;
    const int VALUE_W = 30;

    auto row = [&](const std::string& label, const std::string& value) {
        std::cout << "║ " << std::left << std::setw(LABEL_W) << label
                << "║ " << std::setw(VALUE_W) << value << "     ║\n";
    };

    std::cout << "\n\n"
    "╔══════════════════════════════════════════════════════════╗\n"
    "║                  UC ADMISSIONS ANALYTICS PORTAL          ║\n"
    "╠══════════════════════════════════════════════════════════╣\n";

    row("School:", userSchool);
    row("Year:", std::to_string(userYear));
    row("Major:", userMajor);

    std::cout <<
    "╠══════════════════════════════════════════════════════════╣\n";

    row("Applicants",      target->applicants);
    row("Admits",          target->admits);
    row("Enrolls",         target->enrolls);
    row("Admit GPA Range", target->admitGPARange);
    row("Enroll GPA Range",target->enrollGPARange);
    row("Admit Rate",      target->admitRate);
    row("Yield Rate",      target->yieldRate);

    std::cout <<
    "╚══════════════════════════════════════════════════════════╝\n\n";

    std::cout << "Would you like to look up another? Yes or No.\n";

    std::string again;

    std::cin >> again;

    if(again == "Yes")
        goAgain = true;
    else
        goAgain = false;

    std::cout << "\n\n";

    }
    return 0;

}