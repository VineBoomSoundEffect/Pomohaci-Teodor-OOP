#include "Student.h"
#include "funcs.h"
#include <string.h>

int compareName(Student s1, Student s2) {
    char *x1 = s1.GetName();
    char *x2 = s2.GetName();
    return strcmp(x1, x2);
}
int compareMath(Student s1, Student s2) {
    float x1 = s1.GetGradeMath();
    float x2 = s2.GetGradeMath();
    if(x1 > x2) return 1;
    if(x1 < x2) return -1;
    return 0;
}
int compareEng(Student s1, Student s2) {
    float x1 = s1.GetGradeEng();
    float x2 = s2.GetGradeEng();
    if(x1 > x2) return 1;
    if(x1 < x2) return -1;
    return 0;
}
int compareHist(Student s1, Student s2) {
    float x1 = s1.GetGradeHist();
    float x2 = s2.GetGradeHist();
    if(x1 > x2) return 1;
    if(x1 < x2) return -1;
    return 0;
}
int compareAvg(Student s1, Student s2) {
    float x1 = s1.GetAvg();
    float x2 = s2.GetAvg();
    if(x1 > x2) return 1;
    if(x1 < x2) return -1;
    return 0;
}
