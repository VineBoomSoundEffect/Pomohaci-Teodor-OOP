#include "Student.h"
#include <string.h>

void Student::SetName(const char *name) {
    this->name = new char;
    strcpy(this->name, name);
};
char *Student::GetName() {
    return this->name;
}
void Student::SetGradeMath(float grade) {
    this->grade_math = grade;
}
float Student::GetGradeMath() {
    return this->grade_math;
}
void Student::SetGradeEng(float grade) {
    this->grade_eng = grade;
}
float Student::GetGradeEng() {
    return this->grade_eng;
}
void Student::SetGradeHist(float grade) {
    this->grade_hist = grade;
}
float Student::GetGradeHist() {
    return this->grade_hist;
}
float Student::GetAvg() {
    float avg = 0;
    avg += this->grade_math;
    avg += this->grade_eng;
    avg += this->grade_hist;
    avg /= 3;
    return avg;
}
