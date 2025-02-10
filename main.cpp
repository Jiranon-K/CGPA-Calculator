#include <iostream>
#include <iomanip>
#include <vector>
#include "Semester.h"

double calculateCGPA(const std::vector<Semester>& semesters);
void displayResults(const std::vector<Semester>& semesters);
void inputSemesterData(Semester& sem);

int main() {
    std::vector<Semester> semesters;
    int numSemesters;
    
    std::cout << "CGPA Calculator\n";
    std::cout << "Enter number of semesters: ";
    std::cin >> numSemesters;
    
    for (int i = 1; i <= numSemesters; ++i) {
        Semester sem(i);
        inputSemesterData(sem);
        sem.calculateGPA();
        semesters.push_back(sem);
    }
    
    displayResults(semesters);
    std::cout << "\nCGPA: " << std::fixed << std::setprecision(2) 
              << calculateCGPA(semesters) << std::endl;
    
    return 0;
}

void inputSemesterData(Semester& sem) {
    int numCourses;
    std::cout << "\nEnter number of courses for semester " << sem.getSemesterNumber() << ": ";
    std::cin >> numCourses;
    
    std::cin.ignore();
    
    for (int i = 0; i < numCourses; ++i) {
        std::string name, grade;
        int credits;
        
        std::cout << "\nCourse " << (i + 1) << ":\n";
        std::cout << "Name: ";
        std::getline(std::cin, name);
        
        std::cout << "Credits: ";
        std::cin >> credits;
        
        std::cout << "Grade (A, B+, B, C+, C, D+, D, F): ";
        std::cin >> grade;
        std::cin.ignore();
        
        sem.addCourse(Course(name, credits, grade));
    }
}

void displayResults(const std::vector<Semester>& semesters) {
    std::cout << "\nResults:\n";
    std::cout << std::setfill('-') << std::setw(50) << "-" << std::endl;
    std::cout << std::setfill(' ');
    
    for (const Semester& sem : semesters) {
        std::cout << "\nSemester " << sem.getSemesterNumber() << " GPA: " 
                  << std::fixed << std::setprecision(2) << sem.getGPA() << "\n";
        
        std::cout << std::left << std::setw(30) << "Course Name" 
                  << std::setw(10) << "Credits" 
                  << std::setw(10) << "Grade" << "\n";
                  
        for (const Course& course : sem.getCourses()) {
            std::cout << std::left << std::setw(30) << course.getCourseName()
                      << std::setw(10) << course.getCredits()
                      << std::setw(10) << course.getGrade() << "\n";
        }
    }
}

double calculateCGPA(const std::vector<Semester>& semesters) {
    double totalGPA = 0.0;
    for (const Semester& sem : semesters) {
        totalGPA += sem.getGPA();
    }
    return semesters.size() > 0 ? totalGPA / semesters.size() : 0.0;
}


