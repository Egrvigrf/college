#ifndef STUDENTMANAGEMENT_H
#define STUDENTMANAGEMENT_H

#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

extern const vector<string> subjects;

struct Student {
    string id;
    string name;
    string gender;
    int age;
    string origin;
    int enrollmentYear;
    string className;
    string phoneNumber;
    vector<int> grades;
};

class StudentManagement {
private:
    map<string, Student> students;
public:
    const map<string, Student>& getStudents() const;
    void addStudent(const Student& student);
    void removeStudent(const string& id);
    void queryStudent(const string& id) const;
    void printInfo(const Student& student) const;
    bool validateGender(const string& gender);
    bool validateId(const string& id);
    void printAllStudents();
};

#endif // STUDENTMANAGEMENT_H
