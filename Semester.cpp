#include "Semester.h"

void Semester::addCourse(const Course& course) {
    courses.push_back(course);
}

void Semester::calculateGPA() {
    double totalPoints = 0.0;
    int totalCredits = 0;
    
    for (const Course& course : courses) {
        totalPoints += course.getGradePoint() * course.getCredits();
        totalCredits += course.getCredits();
    }
    
    gpa = totalCredits > 0 ? totalPoints / totalCredits : 0.0;
}
