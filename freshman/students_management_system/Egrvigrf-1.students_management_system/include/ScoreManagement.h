#ifndef SCOREMANAGEMENT_H
#define SCOREMANAGEMENT_H

#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include "StudentManagement.h"
#include "ClassManagement.h"

using namespace std;

struct StudentScore {
    int total;
    string studentID;
    string name;
    string classID;
    string major;
};

class ScoreManagement {
public:
    void queryAllScores(const StudentManagement& studentManager, const ClassManagement& classManager) const;
    void queryClassScores(const string& classID, const ClassManagement& classManager, const StudentManagement& studentManager) const;
    void querySubjectStats(const StudentManagement& studentManager) const;
};

#endif // SCOREMANAGEMENT_H
