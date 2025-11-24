/*
--------------------------------------------------------------------------------
Represents a single major’s admission data for a specific year.

Struct: Major
- Holds all relevant admissions metrics for one major:
    • Broad discipline
    • College/school
    • Major name
    • Applicants, admits, enrolls
    • Admit GPA range
    • Enroll GPA range
    • Admit rate (%)
    • Yield rate (%)

Notes:
- This struct contains no behavior—just data fields.
- Instances of Major will be stored in a vector inside each YearNode.
- No dynamic memory needed here.
--------------------------------------------------------------------------------
*/


#ifndef MAJOR_H
#define MAJOR_H

#include <string>

struct Major {
    std::string broadDiscipline;
    std::string college;
    std::string majorName;

    int applicants;
    int admits;
    int enrolls;

    std::string admitGPARange;
    std::string enrollGPARange;

    int admitRate;
    int yieldRate;
};

#endif
