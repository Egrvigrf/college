#include "../include/StudentManagement.h"

const vector<string> subjects = {"College English", "Advanced Mathematics", "Object Oriented Programming (C++)", "College Physics", "College PE", "Military Theory", "Labor Education Theory"};

const map<string, Student>& StudentManagement::getStudents() const {
    return students;
}

void StudentManagement::addStudent(const Student& student) {
    students[student.id] = student;
}

void StudentManagement::removeStudent(const string& id) {
    students.erase(id);
}

void StudentManagement::queryStudent(const string& id) const {
    auto it = students.find(id);
    if (it != students.end()) {
        printInfo(it->second);
    } else {
        cout << "Student not found." << endl;
    }
}

void StudentManagement::printInfo(const Student& student) const {
    cout << "ID: " << student.id << "\nName: " << student.name << "\nGender: " << student.gender
         << "\nAge: " << student.age << "\nOrigin: " << student.origin
         << "\nEnrollment Year: " << student.enrollmentYear << "\nClass: " << student.className
         << "\nPhone: " << student.phoneNumber << "\nGrades:\n";

    // 假设有一个科目名称的向量 subjects
    vector<string> subjects = {"English", "Math", "C++", "Physics", "PE", "Military Theory", "Labor Education"};

    // 确保科目数量和分数数量一致
    if (subjects.size() == student.grades.size()) {
        for (size_t i = 0; i < subjects.size(); ++i) {
            cout << subjects[i] << ": " << student.grades[i] << "\n";
        }
    } else {
        cout << "Error: Mismatch between number of subjects and grades." << endl;
    }
}

void StudentManagement::printAllStudents()  {
    for (const auto& pair : students) {
        const Student& student = pair.second;
        cout << "ID: " << student.id << "\n"
                  << "Name: " << student.name << "\n"
                  << "Gender: " << student.gender << "\n"
                  << "Age: " << student.age << "\n"
                  << "Origin: " << student.origin << "\n"
                  << "Enrollment Year: " << student.enrollmentYear << "\n"
                  << "Class: " << student.className << "\n"
                  << "Phone: " << student.phoneNumber << "\n"
                  << "Grades: ";
        for (int grade : student.grades) {
            cout << grade << " ";
        }
        cout << "\n------------------------\n";
    }
}



bool StudentManagement::validateGender(const string& gender) {
    return gender == "M" || gender == "F";
}

bool StudentManagement::validateId(const string& id) {
    for (char c : id) {
        if (!isalnum(c)) {
            return false;
        }
    }
    return true;
}
