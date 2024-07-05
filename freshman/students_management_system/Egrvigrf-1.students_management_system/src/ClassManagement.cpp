#include "../include/ClassManagement.h"

void ClassManagement::addClass(const string& classID, const string& major) {
    classes[classID] = major;
    classStudents[classID] = vector<string>();
}

void ClassManagement::removeClass(const string& classID) {
    if (classes.erase(classID)) {
        classStudents.erase(classID);
        cout << "Class removed successfully!" << endl;
    } else {
        cout << "Class not found." << endl;
    }
}

bool ClassManagement::classExists(const string& classID) const {
    return classes.find(classID) != classes.end();
}

string ClassManagement::getClassMajor(const string& classID) const {
    return classes.at(classID);
}

void ClassManagement::addStudentToClass(const string& classID, const string& studentID) {
    classStudents[classID].push_back(studentID);
}

void ClassManagement::removeStudentFromClass(const string& classID, const string& studentID) {
    auto& students = classStudents[classID];
    students.erase(remove(students.begin(), students.end(), studentID), students.end());
}

void ClassManagement::queryClass(const string& classID, const StudentManagement& studentManager) const {
    auto it = classStudents.find(classID);
    if (it != classStudents.end()) {
        cout << "Class ID: " << classID << "\nMajor: " << classes.at(classID) << "\nNumber of Students: " << it->second.size() << endl;
    } else {
        cout << "Class not found." << endl;
    }
}

vector<string> ClassManagement::getClassStudents(const string& classID) const {
    return classStudents.at(classID);
}

string ClassManagement::getStudentClass(const string& studentID) const {
    for (const auto& [classID, students] : classStudents) {
        if (find(students.begin(), students.end(), studentID) != students.end()) {
            return classID;
        }
    }
    return "";
}

string ClassManagement::getStudentMajor(const string& studentID) const {
    string classID = getStudentClass(studentID);
    if (!classID.empty()) {
        return classes.at(classID);
    }
    return "";
}

vector<string> ClassManagement::getMajorClasses(const string& major) const {
    vector<string> majorClasses;
    for (const auto& [classID, classMajor] : classes) {
        if (classMajor == major) {
            majorClasses.push_back(classID);
        }
    }
    return majorClasses;
}

