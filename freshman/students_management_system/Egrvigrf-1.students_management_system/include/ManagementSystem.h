#ifndef MANAGEMENTSYSTEM_H
#define MANAGEMENTSYSTEM_H

#include "StudentManagement.h"
#include "ClassManagement.h"
#include "ScoreManagement.h"

class ManagementSystem {
private:
    StudentManagement studentManager;
    ClassManagement classManager;
    ScoreManagement scoreManager;
public:
    void printMenu();
    void menuStudent();
    void menuClass();
    void menuScore();
    void handleStudentManagement();
    void handleClassManagement();
    void handleScoreManagement();
    void run();
};

int getValidGrade(const string& subject);
void clear_screen();

#endif // MANAGEMENTSYSTEM_H
