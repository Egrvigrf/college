#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <cctype>
using namespace std;

class Student {
private:
    string id;
    string name;
    string gender;
    int age;
    string origin;
    string major;
    int enrollmentYear;
    string className;
    string phoneNumber;
    vector<int> grades;

public:
    Student(const string &id, const string &name, const string &gender, int age, 
            const string &origin, const string &major, int enrollmentYear, 
            const string &className, const string &phoneNumber, const vector<int> &grades)
        : id(id), name(name), gender(gender), age(age), origin(origin), major(major), 
          enrollmentYear(enrollmentYear), className(className), phoneNumber(phoneNumber), grades(grades) {}

    string getId() const { return id; }
    string getName() const { return name; }
    string getGender() const { return gender; }
    int getAge() const { return age; }
    string getOrigin() const { return origin; }
    string getMajor() const { return major; }
    int getEnrollmentYear() const { return enrollmentYear; }
    string getClassName() const { return className; }
    string getPhoneNumber() const { return phoneNumber; }
    vector<int> getGrades() const { return grades; }
    int getTotalScore() const { return accumulate(grades.begin(), grades.end(), 0); }
    double getAverageScore() const { return static_cast<double>(getTotalScore()) / grades.size(); }
    bool isPassing() const { return all_of(grades.begin(), grades.end(), [](int grade) { return grade >= 60; }); }
};

class StudentManagement {
private:
    vector<Student> students;

    vector<int> calculateColumnWidths() {
        vector<int> columnWidths(11, 0);
        vector<string> headers = {"ID", "Name", "Gender", "Age", "Origin", "Major", "Enrollment Year", "Class", "Phone Number", "Total Score", "Average Score"};
        
        for (size_t i = 0; i < headers.size(); ++i) {
            columnWidths[i] = headers[i].length();
        }

        for (const Student &student : students) {
            columnWidths[0] = max(columnWidths[0], (int)student.getId().length());
            columnWidths[1] = max(columnWidths[1], (int)student.getName().length());
            columnWidths[2] = max(columnWidths[2], (int)student.getGender().length());
            columnWidths[3] = max(columnWidths[3], (int)to_string(student.getAge()).length());
            columnWidths[4] = max(columnWidths[4], (int)student.getOrigin().length());
            columnWidths[5] = max(columnWidths[5], (int)student.getMajor().length());
            columnWidths[6] = max(columnWidths[6], (int)to_string(student.getEnrollmentYear()).length());
            columnWidths[7] = max(columnWidths[7], (int)student.getClassName().length());
            columnWidths[8] = max(columnWidths[8], (int)student.getPhoneNumber().length());
            columnWidths[9] = max(columnWidths[9], (int)to_string(student.getTotalScore()).length());
            columnWidths[10] = max(columnWidths[10], (int)to_string(static_cast<int>(student.getAverageScore())).length() + 3); // 3 for decimal places
        }

        for (int &width : columnWidths) {
            width += 2;
        }

        return columnWidths;
    }

    void displayStudentTableHeader(const vector<int>& columnWidths) {
        cout << left << setw(columnWidths[0]) << "ID"
             << setw(columnWidths[1]) << "Name"
             << setw(columnWidths[2]) << "Gender"
             << setw(columnWidths[3]) << "Age"
             << setw(columnWidths[4]) << "Origin"
             << setw(columnWidths[5]) << "Major"
             << setw(columnWidths[6]) << "Enrollment Year"
             << setw(columnWidths[7]) << "Class"
             << setw(columnWidths[8]) << "Phone Number"
             << setw(columnWidths[9]) << "Total Score"
             << setw(columnWidths[10]) << "Average Score" << "\n";
    }

    void displayStudentTableRow(const Student &student, const vector<int>& columnWidths) {
        cout << left << setw(columnWidths[0]) << student.getId()
             << left <<setw(columnWidths[1]) << student.getName()
             << left <<setw(columnWidths[2]) << student.getGender()
             << left <<setw(columnWidths[3]) << student.getAge()
             << left <<setw(columnWidths[4]) << student.getOrigin()
             << left <<setw(columnWidths[5]) << student.getMajor()
             << left <<setw(columnWidths[6]) << student.getEnrollmentYear()
             << left <<setw(columnWidths[7]) << student.getClassName()
             << left <<setw(columnWidths[8]) << student.getPhoneNumber()
             << left <<setw(columnWidths[9]) << student.getTotalScore()
             << left <<setw(columnWidths[10]) << fixed << setprecision(2) << student.getAverageScore() << "\n";
    }

public:
    void addStudent(const Student &student) {
        students.push_back(student);
    }

    void deleteStudent(const string &id) {
        auto it = remove_if(students.begin(), students.end(), [&id](const Student &s) { return s.getId() == id; });
        if (it != students.end()) {
            students.erase(it, students.end());
            cout << "Student with ID " << id << " has been deleted." << endl;
        } else {
            cerr << "Error: Student not found." << endl;
        }
    }

    Student* findStudent(const string &id) {
        auto it = find_if(students.begin(), students.end(), [&id](const Student &s) { return s.getId() == id; });
        if (it != students.end()) {
            return &(*it);
        } else {
            cerr << "Error: Student not found." << endl;
            return nullptr;
        }
    }

    void displayStudent(const string &id) {
        Student* student = findStudent(id);
        if (student) {
            vector<int> columnWidths = calculateColumnWidths();
            displayStudentTableHeader(columnWidths);
            displayStudentTableRow(*student, columnWidths);
        }
    }

    void displayAllStudents() {
        vector<int> columnWidths = calculateColumnWidths();
        displayStudentTableHeader(columnWidths);
        for (const Student &student : students) {
            displayStudentTableRow(student, columnWidths);
        }
    }

    void rankStudents() {
        sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
            return a.getTotalScore() > b.getTotalScore();
        });

        cout << "Rankings:" << endl;
        for (size_t i = 0; i < students.size(); ++i) {
            cout << "Rank " << i + 1 << ": " << students[i].getName() << " - Total Score: " << students[i].getTotalScore() << endl;
        }
    }

    void calculateSubjectStatistics(int subjectIndex) {
        if (students.empty() || subjectIndex >= students[0].getGrades().size()) {
            cerr << "Error: Invalid subject index." << endl;
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

        cout << "Subject " << subjectIndex + 1 << " - Average Score: " << averageScore << "\nPassing Rate: " << passingRate << "%" << endl;
    }

    void prepopulateStudents() {
        vector<string> names = {"张伟", "王芳", "李娜", "刘洋", "陈强", "杨静", "赵磊", "周红", "吴敏", "徐丽",
                                "孙浩", "马敏", "朱玲", "胡强", "郭丽", "何伟", "高芳", "林娜", "罗洋", "郑伟",
                                "梁静", "宋磊", "谢红", "唐敏", "韩丽", "冯浩", "董敏", "程玲", "曹强", "袁娜"};
        vector<string> origins = {"北京", "上海", "广州", "深圳", "天津", "重庆", "杭州", "南京", "武汉", "成都",
                                  "西安", "苏州", "沈阳", "青岛", "大连", "郑州", "长沙", "东莞", "佛山", "福州",
                                  "无锡", "合肥", "昆明", "哈尔滨", "济南", "宁波", "南昌", "南宁", "泉州", "贵阳"};
        vector<string> majors = {"计算机科学与技术", "软件工程", "信息安全", "网络工程", "人工智能", "数据科学与大数据技术", "电子信息工程", "自动化", "通信工程", "机械工程"};
        vector<string> classNames = {"101", "102", "103", "104", "105", "201", "202", "203", "204", "205"};
        vector<string> phoneNumbers = {"18800000001", "18800000002", "18800000003", "18800000004", "18800000005",
                                       "18800000006", "18800000007", "18800000008", "18800000009", "18800000010",
                                       "18800000011", "18800000012", "18800000013", "18800000014", "18800000015",
                                       "18800000016", "18800000017", "18800000018", "18800000019", "18800000020",
                                       "18800000021", "18800000022", "18800000023", "18800000024", "18800000025",
                                       "18800000026", "18800000027", "18800000028", "18800000029", "18800000030"};
        vector<vector<int>> grades = {{85, 90, 88, 92, 85, 90, 88}, {75, 70, 78, 82, 75, 80, 78}, {95, 100, 98, 92, 85, 90, 88},
                                      {65, 60, 68, 72, 65, 70, 68}, {55, 50, 58, 62, 55, 60, 58}, {85, 90, 88, 82, 85, 90, 88},
                                      {75, 70, 78, 72, 75, 80, 78}, {95, 100, 98, 92, 95, 100, 98}, {65, 60, 68, 72, 65, 70, 68},
                                      {55, 50, 58, 62, 55, 60, 58}, {85, 90, 88, 92, 85, 90, 88}, {75, 70, 78, 82, 75, 80, 78},
                                      {95, 100, 98, 92, 85, 90, 88}, {65, 60, 68, 72, 65, 70, 68}, {55, 50, 58, 62, 55, 60, 58},
                                      {85, 90, 88, 82, 85, 90, 88}, {75, 70, 78, 72, 75, 80, 78}, {95, 100, 98, 92, 95, 100, 98},
                                      {65, 60, 68, 72, 65, 70, 68}, {55, 50, 58, 62, 55, 60, 58}, {85, 90, 88, 92, 85, 90, 88},
                                      {75, 70, 78, 82, 75, 80, 78}, {95, 100, 98, 92, 85, 90, 88}, {65, 60, 68, 72, 65, 70, 68},
                                      {55, 50, 58, 62, 55, 60, 58}, {85, 90, 88, 82, 85, 90, 88}, {75, 70, 78, 72, 75, 80, 78},
                                      {95, 100, 98, 92, 95, 100, 98}, {65, 60, 68, 72, 65, 70, 68}, {55, 50, 58, 62, 55, 60, 58}};
        for (int i = 0; i < 30; ++i) {
            stringstream ss;
            ss << "2023" << setfill('0') << setw(6) << i + 1;
            string id = ss.str();
            int age = 18 + (i % 5);
            string gender = (i % 2 == 0) ? "M" : "F";
            int enrollmentYear = 2023;
            Student student(id, names[i], gender, age, origins[i], majors[i % 10], enrollmentYear, classNames[i % 10], phoneNumbers[i], grades[i]);
            addStudent(student);
        }
    }
};

void displayMenu() {
    cout << "==============================\n";
    cout << "  Student Management System\n";
    cout << "==============================\n";
    cout << "1. Add Student\n";
    cout << "2. Delete Student\n";
    cout << "3. Find Student\n";
    cout << "4. Display All Students\n";
    cout << "5. Rank Students\n";
    cout << "6. Calculate Subject Statistics\n";
    cout << "7. Exit\n";
    cout << "==============================\n";
    cout << "Enter your choice: ";
}

// Function to check if a string contains only digits and alphabets
bool isAlphaNumeric(const string &str) {
    return all_of(str.begin(), str.end(), ::isalnum);
}

// Function to extract enrollment year from student ID
int extractEnrollmentYear(const string &id) {
    return stoi(id.substr(0, 4));
}

int main() {
    StudentManagement stu;
    stu.prepopulateStudents(); // 预存储30个学生信息
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 7) {
            break;
        }

        switch (choice) {
        case 1: {
            string id, name, gender, origin, major, className, phoneNumber;
            int age, enrollmentYear;

            while (true) {
                cout << "Enter Student ID (digits and characters only): ";
                cin >> id;
                if (id.length() >= 4 && isAlphaNumeric(id)) {
                    enrollmentYear = extractEnrollmentYear(id);
                    break;
                } else {
                    cerr << "Error: Invalid ID format. ID must be alphanumeric and at least 4 characters long." << endl;
                }
            }

            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, name);
            
            while (true) {
                cout << "Enter Student Gender (M/F): ";
                cin >> gender;
                if (gender == "M" || gender == "F") {
                    break;
                } else {
                    cerr << "Error: Invalid gender. Must be 'M' for Male or 'F' for Female." << endl;
                }
            }
            
            cout << "Enter Student Age: ";
            cin >> age;
            cout << "Enter Student Origin: ";
            cin.ignore();
            getline(cin, origin);
            cout << "Enter Student Major: ";
            getline(cin, major);
            cout << "Enter Student Class: ";
            cin >> className;
            cout << "Enter Phone Number: ";
            cin >> phoneNumber;
            vector<int> grades(7);
            const vector<string> subjects = {"大学英语", "高等数学", "面向对象程序设计(C++)", "大学物理", "大学体育", "军事理论", "劳动教育理论"};
            cout << "Enter grades for the following subjects:\n";
            for (size_t i = 0; i < subjects.size(); ++i) {
                cout << subjects[i] << ": ";
                cin >> grades[i];
            }
            stu.addStudent(Student(id, name, gender, age, origin, major, enrollmentYear, className, phoneNumber, grades));
            cout << "Student added successfully." << endl;
            break;
        }
        case 2: {
            string id;
            cout << "Enter Student ID to delete: ";
            cin >> id;
            stu.deleteStudent(id);
            break;
        }
        case 3: {
            string id;
            cout << "Enter Student ID to find: ";
            cin >> id;
            stu.displayStudent(id);
            break;
        }
        case 4:
            stu.displayAllStudents();
            break;
        case 5:
            stu.rankStudents();
            break;
        case 6: {
            int subjectIndex;
            cout << "Enter subject index (0-6): ";
            cin >> subjectIndex;
            stu.calculateSubjectStatistics(subjectIndex);
            break;
        }
        default:
            cerr << "Error: Invalid choice. Please enter a number from 1 to 7." << endl;
        }
    }

    return 0;
}
