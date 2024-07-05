#include "../include/ManagementSystem.h"



void ManagementSystem::printMenu() {
    cout << "--------------------------------------------" << endl;
    cout << "| Welcome to the Student Management System |" << endl;
    cout << "------------------Main Menu-----------------" << endl;
    cout << "| 1 - Student Management                   |" << endl;
    cout << "| 2 - Class Management                     |" << endl;
    cout << "| 3 - Score Management                     |" << endl;
    cout << "| 0 - Exit System                          |" << endl;
    cout << "--------------------------------------------" << endl;
}

void ManagementSystem::menuStudent() {
    cout << "----------------------------" << endl;
    cout << "|    Student Management    |" << endl;
    cout << "----------------------------" << endl;
    cout << "| 1 - Add Student          |" << endl;
    cout << "| 2 - Query Student        |" << endl;
    cout << "| 3 - Remove Student       |" << endl;
    cout << "| 4 - Display Students     |" << endl;
    cout << "| 0 - Return to Previous   |" << endl;
    cout << "----------------------------" << endl;
}

void ManagementSystem::menuClass() {
    cout << "----------------------------" << endl;
    cout << "|    Class Management      |" << endl;
    cout << "---------------------------|" << endl;
    cout << "| 1 - Add Class            |" << endl;
    cout << "| 2 - Query Class          |" << endl;
    cout << "| 3 - Remove Class         |" << endl;
    cout << "| 0 - Return to Previous   |" << endl;
    cout << "----------------------------" << endl;
}

void ManagementSystem::menuScore() {
    cout << "----------------------------" << endl;
    cout << "|   Score Management       |" << endl;
    cout << "----------------------------" << endl;
    cout << "| 1 - Query All Scores     |" << endl;
    cout << "| 2 - Query Class Scores   |" << endl;
    cout << "| 3 - Query Subject Stats  |" << endl;
    cout << "| 0 - Return to Previous   |" << endl;
    cout << "----------------------------" << endl;
}
void ManagementSystem::handleStudentManagement() {
    int studentOpt;
    while (true) {
        menuStudent();
        cin >> studentOpt;
        if (studentOpt == 0) {
            clear_screen();
            break;
        }
        string id, name, gender, origin, className, phoneNumber;
        int age, enrollmentYear;
        vector<int> grades(subjects.size()); // 根据科目数量调整成绩数量

        switch (studentOpt) {
            case 1: {
                while (true) {
                    cout << "Enter Student ID: "; cin >> id;
                    if (!studentManager.validateId(id)) {
                        cout << "Invalid ID, please re-enter." << endl;
                        continue;
                    }
                    break;
                }

                cout << "Enter Student Name: "; cin >> name;

                while (true) {
                    cout << "Enter Gender (M/F): "; cin >> gender;
                    if (!studentManager.validateGender(gender)) {
                        cout << "Invalid gender, please re-enter." << endl;
                        continue;
                    }
                    break;
                }

                cout << "Enter Age: "; cin >> age;
                cout << "Enter Origin: "; cin >> origin;

                while (true) {
                    cout << "Enter Class: "; cin >> className;
                    if (!classManager.classExists(className)) {
                        cout << "Class does not exist, please re-enter." << endl;
                        continue;
                    }
                    break;
                }

                string major = classManager.getClassMajor(className);

                cout << "Enter Enrollment Year: "; cin >> enrollmentYear;
                cout << "Enter Phone Number: "; cin >> phoneNumber;
                cout << "Enter Grades: ";
                for (size_t i = 0; i < subjects.size(); ++i) {
                    grades[i] = getValidGrade(subjects[i]);
                }

                Student s{id, name, gender, age, origin, enrollmentYear, className, phoneNumber, grades};
                studentManager.addStudent(s);
                classManager.addStudentToClass(className, id);
                cout << "Student added successfully!" << endl;
                break;
            }
            case 2: {
                cout << "Enter Student ID: "; cin >> id;
                studentManager.queryStudent(id);
                break;
            }
            case 3: {
                cout << "Enter Student ID: "; cin >> id;
                if (studentManager.getStudents().find(id) != studentManager.getStudents().end()) {
                    classManager.removeStudentFromClass(studentManager.getStudents().at(id).className, id);
                    studentManager.removeStudent(id);
                }
                break;
            }
            case 4: {
                studentManager.printAllStudents();
                break;
            }
            default:
                cout << "Invalid option, please re-enter." << endl;
        }
    }
}

void ManagementSystem::handleClassManagement() {
    int classOpt;
    while (true) {
        menuClass();
        cin >> classOpt;
        if (classOpt == 0) {
            clear_screen();
            break;
        }
        string classID, major;

        switch (classOpt) {
            case 1: {
                cout << "Enter Class ID: "; cin >> classID;
                cout << "Enter Major: "; cin >> major;
                classManager.addClass(classID, major);
                cout << "Class added successfully!" << endl;
                break;
            }
            case 2: {
                cout << "Enter Class ID: "; cin >> classID;
                classManager.queryClass(classID, studentManager);
                break;
            }
            case 3: {
                cout << "Enter Class ID: "; cin >> classID;
                classManager.removeClass(classID);
                break;
            }
            default:
                cout << "Invalid option, please re-enter." << endl;
        }
    }
}

void ManagementSystem::handleScoreManagement() {
    int scoreOpt;
    while (true) {
        menuScore();
        cin >> scoreOpt;
        if (scoreOpt == 0) {
            clear_screen();
            break;
        }
        string classID;

        switch (scoreOpt) {
            case 1:
                scoreManager.queryAllScores(studentManager, classManager);
                break;
            case 2:
                cout << "Enter Class ID: "; cin >> classID;
                scoreManager.queryClassScores(classID, classManager, studentManager);
                break;
            case 3:
                scoreManager.querySubjectStats(studentManager);
                break;
            default:
                cout << "Invalid option, please re-enter." << endl;
        }
    }
}

void ManagementSystem::run() {
    int opt;
    printMenu();
    while (cin >> opt && opt) {
        clear_screen();
        switch (opt) {
            case 1: 
                handleStudentManagement();
                break;
            case 2: 
                handleClassManagement();
                break;
            case 3: 
                handleScoreManagement();
                break;
            case 0:
                clear_screen();
                return;
            default:
                cout << "Invalid option, please re-enter." << endl;
        }
        printMenu();
    }
}

void clear_screen() {
    cout << "\033[2J\033[1;1H";
}

int getValidGrade(const string& subject) {
    int grade;
    while (true) {
        cout << subject << ": ";
        cin >> grade;
        if (grade >= 0 && grade <= 100) break;
        cout << "Invalid grade, please enter a value between 0 and 100." << endl;
    }
    return grade;
}
