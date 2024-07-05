#include "../include/ScoreManagement.h"

void ScoreManagement::queryAllScores(const StudentManagement& studentManager, const ClassManagement& classManager) const {
    vector<StudentScore> scores;
    for (const auto& [id, student] : studentManager.getStudents()) {
        int total = accumulate(student.grades.begin(), student.grades.end(), 0);
        string classID = classManager.getStudentClass(id);
        string major = classManager.getStudentMajor(id);
        scores.push_back({ total, id, student.name, classID, major });
    }
    sort(scores.begin(), scores.end(), [](const StudentScore& a, const StudentScore& b) {
        return a.total > b.total;
        });

    vector<string> headers = { "Student ID", "Name", "Class", "Major", "Total Score", "Major Rank", "Class Rank" };
    vector<int> colWidths(headers.size(), 0);

    // 计算每一列的宽度
    for (size_t i = 0; i < headers.size(); ++i) {
        colWidths[i] = headers[i].length();
    }
    for (const auto& score : scores) {
        colWidths[0] = max(colWidths[0], static_cast<int>(score.studentID.length()));
        colWidths[1] = max(colWidths[1], static_cast<int>(score.name.length()));
        colWidths[2] = max(colWidths[2], static_cast<int>(score.classID.length()));
        colWidths[3] = max(colWidths[3], static_cast<int>(score.major.length()));
        colWidths[4] = max(colWidths[4], static_cast<int>(to_string(score.total).length()));
        colWidths[5] = max(colWidths[5], static_cast<int>(to_string(score.total).length()));
        colWidths[6] = max(colWidths[6], static_cast<int>(to_string(score.total).length()));
    }

    // 打印表格头线
    cout << "+";
    for (size_t i = 0; i < headers.size(); ++i) {
        cout << string(colWidths[i] + 2, '-') << "+";
    }
    cout << endl;

    // 打印表头
    cout << "|";
    for (size_t i = 0; i < headers.size(); ++i) {
        cout << " " << left << setw(colWidths[i]) << headers[i] << " |";
    }
    cout << endl;

    // 打印表格分隔线
    cout << "+";
    for (size_t i = 0; i < headers.size(); ++i) {
        cout << string(colWidths[i] + 2, '-') << "+";
    }
    cout << endl;

    // 打印学生成绩
    map<string, int> classRanks;
    map<string, int> majorRanks;
    for (size_t i = 0; i < scores.size(); ++i) {
        const auto& score = scores[i];
        classRanks[score.classID]++;
        majorRanks[score.major]++;
        cout << "| " << left << setw(colWidths[0]) << score.studentID << " | "
            << setw(colWidths[1]) << score.name << " | "
            << setw(colWidths[2]) << score.classID << " | "
            << setw(colWidths[3]) << score.major << " | "
            << setw(colWidths[4]) << score.total << " | "
            << setw(colWidths[5]) << majorRanks[score.major] << " | "
            << setw(colWidths[6]) << classRanks[score.classID] << " |" << endl;
    }
    // 打印表格尾线
    cout << "+";
    for (size_t i = 0; i < headers.size(); ++i) {
        cout << string(colWidths[i] + 2, '-') << "+";
    }
    cout << endl;
}




void ScoreManagement::queryClassScores(const string& classID, const ClassManagement& classManager, const StudentManagement& studentManager) const {
    if (classManager.classExists(classID)) {
        vector<vector<double>> subjectAverages(subjects.size(), vector<double>(3, 0)); // 平均分, 合格率, 优秀率
        vector<int> studentCount(subjects.size(), 0);
        vector<int> passCount(subjects.size(), 0);
        vector<int> excellentCount(subjects.size(), 0);

        double totalAverage = 0.0;
        int totalCount = 0;

        for (const string& studentID : classManager.getClassStudents(classID)) {
            const Student& student = studentManager.getStudents().at(studentID);
            totalAverage += accumulate(student.grades.begin(), student.grades.end(), 0) / static_cast<double>(student.grades.size());
            totalCount++;

            for (size_t i = 0; i < subjects.size(); ++i) {
                subjectAverages[i][0] += student.grades[i];
                studentCount[i]++;
                if (student.grades[i] >= 60) passCount[i]++;
                if (student.grades[i] >= 90) excellentCount[i]++;
            }
        }

        totalAverage /= totalCount;

        for (size_t i = 0; i < subjects.size(); ++i) {
            subjectAverages[i][0] /= studentCount[i];
            subjectAverages[i][1] = static_cast<double>(passCount[i]) / studentCount[i] * 100;
            subjectAverages[i][2] = static_cast<double>(excellentCount[i]) / studentCount[i] * 100;
        }

        vector<string> headers = { "Subject", "Avg Score", "Pass Rate", "Excl. Rate" };
        vector<int> colWidths(headers.size(), 0);

        // 计算每一列的宽度
        for (size_t i = 0; i < headers.size(); ++i) {
            colWidths[i] = headers[i].length();
        }
        for (size_t i = 0; i < subjects.size(); ++i) {
            colWidths[0] = max(colWidths[0], static_cast<int>(subjects[i].length()));
        }

        // 打印表格头线
        cout << "+";
        for (size_t i = 0; i < headers.size(); ++i) {
            cout << string(colWidths[i] + 2, '-') << "+";
        }
        cout << endl;

        // 打印表头
        cout << "| ";
        for (size_t i = 0; i < headers.size(); ++i) {
            cout << left << setw(colWidths[i] + 1) << headers[i] << "| ";
        }
        cout << endl;

        // 打印表格分隔线
        cout << "+";
        for (size_t i = 0; i < headers.size(); ++i) {
            cout << string(colWidths[i] + 2, '-') << "+";
        }
        cout << endl;

        // 打印各科成绩
        for (size_t i = 0; i < subjects.size(); ++i) {
            // 计算并转换百分比，保留两位小数
            string passRate = to_string(subjectAverages[i][1]).substr(0, to_string(subjectAverages[i][1]).find(".") + 3) + "%";
            string excellentRate = to_string(subjectAverages[i][2]).substr(0, to_string(subjectAverages[i][2]).find(".") + 3) + "%";

            cout << "| " << left << setw(colWidths[0] + 1) << subjects[i] << "| "
                << setw(colWidths[1] + 1) << fixed << setprecision(2) << subjectAverages[i][0] << "| "
                << setw(colWidths[2] + 1) << passRate << "| "
                << setw(colWidths[3] + 1) << excellentRate << "|" << endl;

            // 每行之间添加横线

        }
        cout << "+";
        for (size_t j = 0; j < headers.size(); ++j) {
            cout << string(colWidths[j] + 2, '-') << "+";
        }
        cout << endl;
        // 打印总平均分
        cout << "\nClass " << classID << " Total Average Score: " << fixed << setprecision(2) << totalAverage << endl;
        cout<<endl;
    } else {
        cout << "Class not found." << endl;
    }
}


void ScoreManagement::querySubjectStats(const StudentManagement& studentManager) const {
    vector<int> totalGrades(subjects.size(), 0);
    vector<int> maxGrades(subjects.size(), -1);
    vector<int> minGrades(subjects.size(), 101);
    vector<int> passCount(subjects.size(), 0);
    vector<int> excellentCount(subjects.size(), 0);
    int studentCount = studentManager.getStudents().size();
    if(!studentCount) {
        cout<<"None!"<<endl;
        return;
    }
    for (const auto& [id, student] : studentManager.getStudents()) {
        for (size_t i = 0; i < subjects.size(); ++i) {
            totalGrades[i] += student.grades[i];
            if (student.grades[i] > maxGrades[i]) maxGrades[i] = student.grades[i];
            if (student.grades[i] < minGrades[i]) minGrades[i] = student.grades[i];
            if (student.grades[i] >= 60) passCount[i]++;
            if (student.grades[i] >= 90) excellentCount[i]++;
        }
    }

    for (size_t i = 0; i < subjects.size(); ++i) {
        totalGrades[i] /= studentCount;
    }

    vector<string> headers = { "Subject", "Avg Score", "Max Score", "Min Score", "Pass Rate", "Excl. Rate" };
    vector<int> colWidths(headers.size(), 0);

    // 计算每一列的宽度
    for (size_t i = 0; i < headers.size(); ++i) {
        colWidths[i] = headers[i].length();
    }
    for (size_t i = 0; i < subjects.size(); ++i) {
        colWidths[0] = max(colWidths[0], static_cast<int>(subjects[i].length()));
        colWidths[1] = max(colWidths[1], static_cast<int>(to_string(totalGrades[i]).length()));
        colWidths[2] = max(colWidths[2], static_cast<int>(to_string(maxGrades[i]).length()));
        colWidths[3] = max(colWidths[3], static_cast<int>(to_string(minGrades[i]).length()));
        colWidths[4] = max(colWidths[4], static_cast<int>(to_string(passCount[i]).length()));
        colWidths[5] = max(colWidths[5], static_cast<int>(to_string(excellentCount[i]).length()));
    }

    // 打印表格头线
    cout << "+";
    for (size_t i = 0; i < headers.size(); ++i) {
        cout << string(colWidths[i] + 2, '-') << "+";
    }
    cout << endl;

    // 打印表头
    cout << "| ";
    for (size_t i = 0; i < headers.size(); ++i) {
        cout << left << setw(colWidths[i] + 1) << headers[i] << "| ";
    }
    cout << endl;

    // 打印表格分隔线
    cout << "+";
    for (size_t i = 0; i < headers.size(); ++i) {
        cout << string(colWidths[i] + 2, '-') << "+";
    }
    cout << endl;

    for (size_t i = 0; i < subjects.size(); ++i) {
        // 计算并转换百分比，保留两位小数
        float passRateValue = static_cast<float>(passCount[i]) / studentCount * 100.0;
        float excellentRateValue = static_cast<float>(excellentCount[i]) / studentCount * 100.0;

        string passRate = to_string(passRateValue).substr(0, to_string(passRateValue).find(".") + 3) + "%";
        string excellentRate = to_string(excellentRateValue).substr(0, to_string(excellentRateValue).find(".") + 3) + "%";

        // 打印各科统计
        cout << "| " << left << setw(colWidths[0] + 1) << subjects[i] << "| "
            << setw(colWidths[1] + 1) << fixed << setprecision(2) << static_cast<double>(totalGrades[i]) << "| "
            << setw(colWidths[2] + 1) << maxGrades[i] << "| "
            << setw(colWidths[3] + 1) << minGrades[i] << "| "
            << setw(colWidths[4] + 1) << passRate << "| "
            << setw(colWidths[5] + 1) << excellentRate << "|" << endl;
    }
    cout << "+";
    for (size_t j = 0; j < headers.size(); ++j) {
        cout << string(colWidths[j] + 2, '-') << "+";
    }
    cout << endl << endl;
}

