#ifndef SEMESTER_H
#define SEMESTER_H

#include "Course.h"
#include <vector>

class Semester {
private:
    int semesterNumber;
    std::vector<Course> courses;
    double gpa;

public:
    Semester(int num = 1) : semesterNumber(num), gpa(0.0) {}
    
    void addCourse(const Course& course);
    void calculateGPA();
    double getGPA() const { return gpa; }
    int getSemesterNumber() const { return semesterNumber; }
    const std::vector<Course>& getCourses() const { return courses; }
};

#endif
