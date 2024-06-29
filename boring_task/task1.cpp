#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <numeric>
#include <vector>
#include <string>
#include <unordered_map>
#include <regex>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define inf 0x3f3f3f3f // 1e9

const double eps = 1e-5;
const vector<string> subjects = {"大学英语", "高等数学", "面向对象程序设计(C++)", "大学物理", "大学体育", "军事理论", "劳动教育理论"};

void clear_screen() {
    cout << "\033[2J\033[1;1H";
}

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

    void printInfo() const {
        cout << "ID: " << id << "\nName: " << name << "\nGender: " << gender << "\nAge: " << age << "\nOrigin: " << origin << "\nEnrollment Year: " << enrollmentYear << "\nClass: " << className << "\nPhone: " << phoneNumber << "\nGrades: ";
        for (int grade : grades) cout << grade << " ";
        cout << endl;
    }
};

class StudentManagement {
private:
    map<string, Student> students;
public:
    bool validateGender(const string& gender) {
        return gender == "M" || gender == "F";
    }

    bool validateId(const string& id) {
        return regex_match(id, regex("^[A-Za-z0-9]+$"));
    }

    void addStudent(const Student& student) {
        students[student.id] = student;
    }

    void removeStudent(const string& id) {
        if (students.erase(id)) {
            cout << "学生删除成功！" << endl;
        } else {
            cout << "未找到该学生信息。" << endl;
        }
    }

    void queryStudent(const string& id) const {
        auto it = students.find(id);
        if (it != students.end()) {
            it->second.printInfo();
        } else {
            cout << "未找到该学生信息。" << endl;
        }
    }

    void printAllStudents() const {
        for (const auto& [id, student] : students) {
            student.printInfo();
        }
    }

    const map<string, Student>& getStudents() const {
        return students;
    }
};

class ClassManagement {
private:
    map<string, string> classes; // classID -> major
    map<string, vector<string>> classStudents; // classID -> studentIDs
public:
    void addClass(const string& classID, const string& major) {
        classes[classID] = major;
        classStudents[classID] = vector<string>();
    }

    void removeClass(const string& classID) {
        if (classes.erase(classID)) {
            classStudents.erase(classID);
            cout << "班级删除成功！" << endl;
        } else {
            cout << "未找到该班级信息。" << endl;
        }
    }

    bool classExists(const string& classID) const {
        return classes.find(classID) != classes.end();
    }

    string getClassMajor(const string& classID) const {
        return classes.at(classID);
    }

    void addStudentToClass(const string& classID, const string& studentID) {
        classStudents[classID].push_back(studentID);
    }

    void removeStudentFromClass(const string& classID, const string& studentID) {
        auto& students = classStudents[classID];
        students.erase(remove(students.begin(), students.end(), studentID), students.end());
    }

    void queryClass(const string& classID, const StudentManagement& studentManager) const {
        auto it = classStudents.find(classID);
        if (it != classStudents.end()) {
            cout << "班级ID: " << classID << "\n专业: " << classes.at(classID) << "\n学生人数: " << it->second.size() << endl;
            cout << "是否列出学生信息？(Y/N): ";
            char choice;
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                for (const string& studentID : it->second) {
                    studentManager.queryStudent(studentID);
                }
            }
        } else {
            cout << "未找到该班级信息。" << endl;
        }
    }

    vector<string> getClassStudents(const string& classID) const {
        return classStudents.at(classID);
    }

    string getStudentClass(const string& studentID) const {
        for (const auto& [classID, students] : classStudents) {
            if (find(students.begin(), students.end(), studentID) != students.end()) {
                return classID;
            }
        }
        return "";
    }

    string getStudentMajor(const string& studentID) const {
        string classID = getStudentClass(studentID);
        if (!classID.empty()) {
            return classes.at(classID);
        }
        return "";
    }

    vector<string> getMajorClasses(const string& major) const {
        vector<string> majorClasses;
        for (const auto& [classID, classMajor] : classes) {
            if (classMajor == major) {
                majorClasses.push_back(classID);
            }
        }
        return majorClasses;
    }
};

class ScoreManagement {
public:
    void queryAllScores(const StudentManagement& studentManager, const ClassManagement& classManager) const {
        vector<tuple<int, string, string, string, string>> scores; // (total, studentID, name, classID, major)
        for (const auto& [id, student] : studentManager.getStudents()) {
            int total = accumulate(student.grades.begin(), student.grades.end(), 0);
            string classID = classManager.getStudentClass(id);
            string major = classManager.getStudentMajor(id);
            scores.push_back(make_tuple(total, id, student.name, classID, major));
        }
        sort(rall(scores));
        
        cout << left << setw(12) << "学号" 
             << setw(12) << "姓名" 
             << setw(12) << "班级" 
             << setw(12) << "专业" 
             << setw(12) << "总成绩" 
             << setw(12) << "专业排名" 
             << setw(12) << "班级排名" << endl;
        cout << "---------------------------------------------------------------------" << endl;

        // 计算班级和专业排名
        map<string, int> classRanks;
        map<string, int> majorRanks;
        for (size_t i = 0; i < scores.size(); ++i) {
            auto& [total, studentID, name, classID, major] = scores[i];
            if (classRanks[classID] == 0) classRanks[classID] = 1;
            else classRanks[classID]++;
            if (majorRanks[major] == 0) majorRanks[major] = 1;
            else majorRanks[major]++;
            cout << left << setw(12) << studentID
                 << setw(12) << name
                 << setw(12) << classID
                 << setw(12) << major
                 << setw(12) << total
                 << setw(12) << majorRanks[major]
                 << setw(12) << classRanks[classID]
                 << endl;
        }
    }

    void queryClassScores(const string& classID, const ClassManagement& classManager, const StudentManagement& studentManager) const {
        if (classManager.classExists(classID)) {
            vector<pair<int, string>> scores;
            for (const string& studentID : classManager.getClassStudents(classID)) {
                const Student& student = studentManager.getStudents().at(studentID);
                int total = accumulate(student.grades.begin(), student.grades.end(), 0);
                scores.push_back({total, studentID});
            }
            sort(rall(scores));
            cout << "班级 " << classID << " 成绩: " << endl;
            cout << left << setw(12) << "总成绩" 
                 << setw(12) << "学号" << endl;
            cout << "------------------------------" << endl;

            for (const auto& entry : scores) {
                cout << left << setw(12) << entry.first
                     << setw(12) << entry.second << endl;
            }
        } else {
            cout << "未找到该班级信息。" << endl;
        }
    }

    void querySubjectStats(const StudentManagement& studentManager) const {
        vector<int> totalGrades(subjects.size(), 0);
        vector<int> maxGrades(subjects.size(), -1);
        vector<int> minGrades(subjects.size(), 101);
        vector<int> passCount(subjects.size(), 0);
        vector<int> excellentCount(subjects.size(), 0);
        int studentCount = studentManager.getStudents().size();

        for (const auto& [id, student] : studentManager.getStudents()) {
            for (int i = 0; i < subjects.size(); ++i) {
                totalGrades[i] += student.grades[i];
                if (student.grades[i] > maxGrades[i]) maxGrades[i] = student.grades[i];
                if (student.grades[i] < minGrades[i]) minGrades[i] = student.grades[i];
                if (student.grades[i] >= 60) passCount[i]++;
                if (student.grades[i] >= 90) excellentCount[i]++;
            }
        }

        cout << left << setw(20) << "科目" 
             << setw(12) << "平均成绩" 
             << setw(12) << "最高成绩" 
             << setw(12) << "最低成绩" 
             << setw(12) << "及格率" 
             << setw(12) << "优秀率" << endl;
        cout << "-----------------------------------------------------------------" << endl;

        for (int i = 0; i < subjects.size(); ++i) {
            cout << left << setw(20) << subjects[i]
                 << setw(12) << fixed << setprecision(2) << (double)totalGrades[i] / studentCount
                 << setw(12) << maxGrades[i]
                 << setw(12) << minGrades[i]
                 << setw(12) << fixed << setprecision(2) << (double)passCount[i] / studentCount * 100 << "%"
                 << setw(12) << fixed << setprecision(2) << (double)excellentCount[i] / studentCount * 100 << "%" 
                 << endl;
        }
    }
};

class ManagementSystem {
private:
    StudentManagement studentManager;
    ClassManagement classManager;
    ScoreManagement scoreManager;

    void initializeData() {
        // 初始化班级信息
        classManager.addClass("2305111B", "计算机科学与技术");
        classManager.addClass("2305112", "软件工程");
        classManager.addClass("2305113", "信息安全");

        // 初始化学生信息
        vector<int> grades1 = {85, 90, 80, 70, 75, 88, 92};
        vector<int> grades2 = {78, 85, 88, 90, 68, 75, 80};
        vector<int> grades3 = {92, 88, 85, 90, 95, 92, 90};
        vector<int> grades4 = {65, 70, 75, 80, 85, 70, 75};
        vector<int> grades5 = {88, 90, 92, 85, 87, 90, 88};

        studentManager.addStudent({"2023002111", "Alice", "F", 20, "北京", 2023, "2305111B", "12345678901", grades1});
        studentManager.addStudent({"2023002112", "Bob", "M", 21, "上海", 2023, "2305111B", "12345678902", grades2});
        studentManager.addStudent({"2023002113", "Charlie", "M", 22, "广州", 2023, "2305111B", "12345678903", grades3});
        studentManager.addStudent({"2023002114", "David", "M", 20, "深圳", 2023, "2305111B", "12345678904", grades4});
        studentManager.addStudent({"2023002115", "Eve", "F", 21, "杭州", 2023, "2305111B", "12345678905", grades5});

        studentManager.addStudent({"2023002121", "Frank", "M", 20, "南京", 2023, "2305112", "12345678906", grades1});
        studentManager.addStudent({"2023002122", "Grace", "F", 21, "武汉", 2023, "2305112", "12345678907", grades2});
        studentManager.addStudent({"2023002123", "Hank", "M", 22, "长沙", 2023, "2305112", "12345678908", grades3});
        studentManager.addStudent({"2023002124", "Ivy", "F", 20, "西安", 2023, "2305112", "12345678909", grades4});
        studentManager.addStudent({"2023002125", "Jack", "M", 21, "成都", 2023, "2305112", "12345678910", grades5});

        studentManager.addStudent({"2023002131", "Karen", "F", 20, "郑州", 2023, "2305113", "12345678911", grades1});
        studentManager.addStudent({"2023002132", "Leo", "M", 21, "重庆", 2023, "2305113", "12345678912", grades2});
        studentManager.addStudent({"2023002133", "Mia", "F", 22, "苏州", 2023, "2305113", "12345678913", grades3});
        studentManager.addStudent({"2023002134", "Nick", "M", 20, "济南", 2023, "2305113", "12345678914", grades4});
        studentManager.addStudent({"2023002135", "Olivia", "F", 21, "大连", 2023, "2305113", "12345678915", grades5});

        for (const auto& [id, student] : studentManager.getStudents()) {
            classManager.addStudentToClass(student.className, id);
        }
    }

public:
    ManagementSystem() {
        initializeData();
    }

    void printMenu() {
        cout << "----------------------" << endl;
        cout << "欢迎来到学生学籍管理系统" << endl;
        cout << "---------主目录--------" << endl;
        cout << "1 - 学生管理" << endl;
        cout << "2 - 班级管理" << endl;
        cout << "3 - 成绩统计" << endl;
        cout << "0 - 退出系统" << endl;
        cout << "----------------------" << endl;
    }

    void menuStudent() {
        cout << "----------------------" << endl;
        cout << "      学生管理        " << endl;
        cout << "----------------------" << endl;
        cout << "1 - 添加学生" << endl;
        cout << "2 - 查询学生" << endl;
        cout << "3 - 删除学生" << endl;
        cout << "0 - 返回上一级目录" << endl;
        cout << "----------------------" << endl;
    }

    void menuClass() {
        cout << "----------------------" << endl;
        cout << "      班级管理        " << endl;
        cout << "----------------------" << endl;
        cout << "1 - 添加班级" << endl;
        cout << "2 - 查询班级" << endl;
        cout << "3 - 删除班级" << endl;
        cout << "0 - 返回上一级目录" << endl;
        cout << "----------------------" << endl;
    }

    void menuScore() {
        cout << "----------------------" << endl;
        cout << "      成绩统计        " << endl;
        cout << "----------------------" << endl;
        cout << "1 - 查询所有学生成绩" << endl;
        cout << "2 - 查询班级成绩" << endl;
        cout << "3 - 查询各科成绩统计" << endl;
        cout << "0 - 返回上一级目录" << endl;
        cout << "----------------------" << endl;
    }

    void handleStudentManagement() {
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
                        cout << "输入学生ID: "; cin >> id;
                        if (!studentManager.validateId(id)) {
                            cout << "学号不合法，请重新输入。" << endl;
                            continue;
                        }
                        break;
                    }

                    cout << "输入学生姓名: "; cin >> name;

                    while (true) {
                        cout << "输入性别 (M/F): "; cin >> gender;
                        if (!studentManager.validateGender(gender)) {
                            cout << "性别不合法，请重新输入。" << endl;
                            continue;
                        }
                        break;
                    }

                    cout << "输入年龄: "; cin >> age;
                    cout << "输入生源地: "; cin >> origin;

                    while (true) {
                        cout << "输入班级: "; cin >> className;
                        if (!classManager.classExists(className)) {
                            cout << "班级不存在，请重新输入。" << endl;
                            continue;
                        }
                        break;
                    }

                    string major = classManager.getClassMajor(className);

                    cout << "输入入学年份: "; cin >> enrollmentYear;
                    cout << "输入联系电话: "; cin >> phoneNumber;
                    cout << "输入各科成绩: ";
                    for (int i = 0; i < subjects.size(); ++i) {
                        cout << subjects[i] << ": ";
                        cin >> grades[i];
                    }

                    Student s{id, name, gender, age, origin, enrollmentYear, className, phoneNumber, grades};
                    studentManager.addStudent(s);
                    classManager.addStudentToClass(className, id);
                    cout << "学生添加成功！" << endl;
                    break;
                }
                case 2: {
                    cout << "输入学生ID: "; cin >> id;
                    studentManager.queryStudent(id);
                    break;
                }
                case 3: {
                    cout << "输入学生ID: "; cin >> id;
                    if (studentManager.getStudents().find(id) != studentManager.getStudents().end()) {
                        classManager.removeStudentFromClass(studentManager.getStudents().at(id).className, id);
                        studentManager.removeStudent(id);
                    }
                    break;
                }
                default:
                    cout << "无效的选项，请重新输入。" << endl;
            }
        }
    }

    void handleClassManagement() {
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
                    cout << "输入班级ID: "; cin >> classID;
                    cout << "输入专业: "; cin >> major;
                    classManager.addClass(classID, major);
                    cout << "班级添加成功！" << endl;
                    break;
                }
                case 2: {
                    cout << "输入班级ID: "; cin >> classID;
                    classManager.queryClass(classID, studentManager);
                    break;
                }
                case 3: {
                    cout << "输入班级ID: "; cin >> classID;
                    classManager.removeClass(classID);
                    break;
                }
                default:
                    cout << "无效的选项，请重新输入。" << endl;
            }
        }
    }

    void handleScoreManagement() {
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
                    cout << "输入班级ID: "; cin >> classID;
                    scoreManager.queryClassScores(classID, classManager, studentManager);
                    break;
                case 3:
                    scoreManager.querySubjectStats(studentManager);
                    break;
                default:
                    cout << "无效的选项，请重新输入。" << endl;
            }
        }
    }

    void run() {
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
                    cout << "无效的选项，请重新输入。" << endl;
            }
            printMenu();
        }
    }
};

int main() {
    IOS;
    ManagementSystem system;
    system.run();
    return 0;
}
