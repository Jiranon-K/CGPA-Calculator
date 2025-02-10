#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
private:
    std::string courseName;
    int credits;
    std::string grade;
    double gradePoint;

public:
    Course(std::string name = "", int cred = 0, std::string grd = "");
    
    void setCourseName(std::string name) { courseName = name; }
    void setCredits(int cred) { credits = cred; }
    void setGrade(std::string grd);
    
    std::string getCourseName() const { return courseName; }
    int getCredits() const { return credits; }
    std::string getGrade() const { return grade; }
    double getGradePoint() const { return gradePoint; }
};

#endif
