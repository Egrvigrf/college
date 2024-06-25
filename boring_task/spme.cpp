#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

class Student {
private:
    std::string id;
    std::string name;
    std::string gender;
    int age;
    std::string origin;
    std::string major;
    int enrollmentYear;
    std::string className;
    std::string phoneNumber;
    std::vector<int> grades; // 依次存储各科成绩：大学英语、高等数学、面向对象程序设计(C++)、大学物理、大学体育、军事理论、劳动教育理论

public:
    Student(const std::string &id, const std::string &name, const std::string &gender, int age, 
            const std::string &origin, const std::string &major, int enrollmentYear, 
            const std::string &className, const std::string &phoneNumber, const std::vector<int> &grades)
        : id(id), name(name), gender(gender), age(age), origin(origin), major(major), 
          enrollmentYear(enrollmentYear), className(className), phoneNumber(phoneNumber), grades(grades) {}

    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getGender() const { return gender; }
    int getAge() const { return age; }
    std::string getOrigin() const { return origin; }
    std::string getMajor() const { return major; }
    int getEnrollmentYear() const { return enrollmentYear; }
    std::string getClassName() const { return className; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::vector<int> getGrades() const { return grades; }
    int getTotalScore() const { return std::accumulate(grades.begin(), grades.end(), 0); }
    double getAverageScore() const { return static_cast<double>(getTotalScore()) / grades.size(); }
    bool isPassing() const { return std::all_of(grades.begin(), grades.end(), [](int grade) { return grade >= 60; }); }
};

class StudentManagement {
private:
    std::vector<Student> students;

public:
    void addStudent(const Student &student) {
        students.push_back(student);
    }

    void deleteStudent(const std::string &id) {
        auto it = std::remove_if(students.begin(), students.end(), [&id](const Student &s) { return s.getId() == id; });
        if (it != students.end()) {
            students.erase(it, students.end());
            std::cout << "Student with ID " << id << " has been deleted." << std::endl;
        } else {
            std::cerr << "Error: Student not found." << std::endl;
        }
    }

    Student* findStudent(const std::string &id) {
        auto it = std::find_if(students.begin(), students.end(), [&id](const Student &s) { return s.getId() == id; });
        if (it != students.end()) {
            return &(*it);
        } else {
            std::cerr << "Error: Student not found." << std::endl;
            return nullptr;
        }
    }

    void displayStudent(const std::string &id) {
        Student* student = findStudent(id);
        if (student) {
            std::cout << "ID: " << student->getId() << "\nName: " << student->getName()
                      << "\nGender: " << student->getGender() << "\nAge: " << student->getAge()
                      << "\nOrigin: " << student->getOrigin() << "\nMajor: " << student->getMajor()
                      << "\nEnrollment Year: " << student->getEnrollmentYear() << "\nClass: " << student->getClassName()
                      << "\nPhone Number: " << student->getPhoneNumber() << "\nGrades: ";
            const std::vector<std::string> subjects = {"大学英语", "高等数学", "面向对象程序设计(C++)", "大学物理", "大学体育", "军事理论", "劳动教育理论"};
            for (size_t i = 0; i < student->getGrades().size(); ++i) {
                std::cout << subjects[i] << ": " << student->getGrades()[i] << " ";
            }
            std::cout << "\nTotal Score: " << student->getTotalScore()
                      << "\nAverage Score: " << student->getAverageScore() << std::endl;
        }
    }

    void displayAllStudents() {
        std::cout << std::left << std::setw(10) << "ID" << std::setw(20) << "Name" << std::setw(10) << "Gender"
                  << std::setw(5) << "Age" << std::setw(20) << "Origin" << std::setw(20) << "Major"
                  << std::setw(15) << "Enrollment Year" << std::setw(10) << "Class" << std::setw(15) << "Phone Number"
                  << std::setw(20) << "Total Score" << "Average Score" << std::endl;
        for (const Student &student : students) {
            std::cout << std::left << std::setw(10) << student.getId() << std::setw(20) << student.getName()
                      << std::setw(10) << student.getGender() << std::setw(5) << student.getAge()
                      << std::setw(20) << student.getOrigin() << std::setw(20) << student.getMajor()
                      << std::setw(15) << student.getEnrollmentYear() << std::setw(10) << student.getClassName()
                      << std::setw(15) << student.getPhoneNumber() << std::setw(20) << student.getTotalScore()
                      << student.getAverageScore() << std::endl;
        }
    }

    void rankStudents() {
        std::sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
            return a.getTotalScore() > b.getTotalScore();
        });

        std::cout << "Rankings:" << std::endl;
        for (size_t i = 0; i < students.size(); ++i) {
            std::cout << "Rank " << i + 1 << ": " << students[i].getName() << " - Total Score: " << students[i].getTotalScore() << std::endl;
        }
    }

    void calculateSubjectStatistics(int subjectIndex) {
        if (students.empty() || subjectIndex >= students[0].getGrades().size()) {
            std::cerr << "Error: Invalid subject index." << std::endl;
            return;
        }

        int totalScore = 0;
        int passingCount = 0;
        int studentCount = students.size();

        for (const Student &student : students) {
            int grade = student.getGrades().at(subjectIndex);
            totalScore += grade;
            if (grade >= 60) {
                passingCount++;
            }
        }

        double averageScore = static_cast<double>(totalScore) / studentCount;
        double passingRate = static_cast<double>(passingCount) / studentCount * 100;

        std::cout << "Subject " << subjectIndex + 1 << " - Average Score: " << averageScore << "\nPassing Rate: " << passingRate << "%" << std::endl;
    }
};

void displayMenu() {
    std::cout << "==============================\n";
    std::cout << "  Student Management System\n";
    std::cout << "==============================\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Delete Student\n";
    std::cout << "3. Find Student\n";
    std::cout << "4. Display All Students\n";
    std::cout << "5. Rank Students\n";
    std::cout << "6. Calculate Subject Statistics\n";
    std::cout << "7. Exit\n";
    std::cout << "==============================\n";
    std::cout << "Enter your choice: ";
}

int main() {
    StudentManagement sm;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

        if (choice == 7) {
            break;
        }

        switch (choice) {
        case 1: {
            std::string id, name, gender, origin, major, className, phoneNumber;
            int age, enrollmentYear;
            std::cout << "Enter Student ID: ";
            std::cin >> id;
            std::cout << "Enter Student Name: ";
            std::cin >> name;
            std::cout << "Enter Student Gender: ";
            std::cin >> gender;
            std::cout << "Enter Student Age: ";
            std::cin >> age;
            std::cout << "Enter Student Origin: ";
            std::cin >> origin;
            std::cout << "Enter Student Major: ";
            std::cin >> major;
            std::cout << "Enter Enrollment Year: ";
            std::cin >> enrollmentYear;
            std::cout << "Enter Student Class: ";
            std::cin >> className;
            std::cout << "Enter Phone Number: ";
            std::cin >> phoneNumber;
            std::vector<int> grades(7);
            const std::vector<std::string> subjects = {"大学英语", "高等数学", "面向对象程序设计(C++)", "大学物理", "大学体育", "军事理论", "劳动教育理论"};
            std::cout << "Enter grades for the following subjects:\n";
            for (size_t i = 0; i < subjects.size(); ++i) {
                std::cout << subjects[i] << ": ";
                std::cin >> grades[i];
            }
            Student student(id, name, gender, age, origin, major, enrollmentYear, className, phoneNumber, grades);
            sm.addStudent(student);
            std::cout << "Student added successfully." << std::endl;
            break;
        }
        case 2: {
            std::string id;
            std::cout << "Enter Student ID to delete: ";
            std::cin >> id;
            sm.deleteStudent(id);
            break;
        }
        case 3: {
            std::string id;
            std::cout << "Enter Student ID to find: ";
            std::cin >> id;
            sm.displayStudent(id);
            break;
        }
        case 4:
            sm.displayAllStudents();
            break;
        case 5:
            sm.rankStudents();
            break;
        case 6: {
            int subjectIndex;
            const std::vector<std::string> subjects = {"大学英语", "高等数学", "面向对象程序设计(C++)", "大学物理", "大学体育", "军事理论", "劳动教育理论"};
            std::cout << "Enter subject index (1-7):\n";
            for (size_t i = 0; i < subjects.size(); ++i) {
                std::cout << i + 1 << ". " << subjects[i] << "\n";
            }
            std::cin >> subjectIndex;
            sm.calculateSubjectStatistics(subjectIndex - 1);  // 调整索引从0开始
            break;
        }
        default:
            std::cerr << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
