#ifndef CLASSMANAGEMENT_H
#define CLASSMANAGEMENT_H

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

using namespace std;

class ClassManagement {
private:
    map<string, string> classes; // classID -> major
    map<string, vector<string>> classStudents; // classID -> studentIDs
public:
    void addClass(const string& classID, const string& major);
    void removeClass(const string& classID);
    bool classExists(const string& classID) const;
    string getClassMajor(const string& classID) const;
    void addStudentToClass(const string& classID, const string& studentID);
    void removeStudentFromClass(const string& classID, const string& studentID);
    void queryClass(const string& classID, const StudentManagement& studentManager) const;
    vector<string> getClassStudents(const string& classID) const;
    string getStudentClass(const string& studentID) const;
    string getStudentMajor(const string& studentID) const;
    vector<string> getMajorClasses(const string& major) const;
};

#endif // CLASSMANAGEMENT_H
