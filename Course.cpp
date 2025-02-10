#include "Course.h"
#include <map>
#include <iostream>

Course::Course(std::string name, int cred, std::string grd) 
    : courseName(name), credits(cred), grade(grd) {
    setGrade(grd);
}

void Course::setGrade(std::string grd) {
    static const std::map<std::string, double> gradePoints = {
        {"A", 4.0}, {"B+", 3.5}, {"B", 3.0},
        {"C+", 2.5}, {"C", 2.0}, {"D+", 1.5},
        {"D", 1.0}, {"F", 0.0}
    };
    
    if (gradePoints.find(grd) == gradePoints.end()) {
        std::cerr << "Invalid grade entered: " << grd << ". Setting to F.\n";
        grade = "F";
        gradePoint = 0.0;
        return;
    }
    
    grade = grd;
    gradePoint = gradePoints.at(grd);
}
