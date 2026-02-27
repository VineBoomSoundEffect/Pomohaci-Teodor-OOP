#include <iostream>
#include "Student.h"
#include "funcs.h"

void printStudent(Student s) {
    std::cout << s.GetName() << "\n";
    std::cout << s.GetGradeMath() << "\n";
    std::cout << s.GetGradeEng() << "\n";
    std::cout << s.GetGradeHist() << "\n";
    std::cout << s.GetAvg() << "\n";
    std::cout << "\n";
}

int main() {
    Student s1;
    s1.SetName("teodor");
    s1.SetGradeMath(4);
    s1.SetGradeEng(9);
    s1.SetGradeHist(8);
    printStudent(s1);
    Student s2;
    s2.SetName("pomohaci");
    s2.SetGradeMath(5);
    s2.SetGradeEng(2);
    s2.SetGradeHist(8);
    printStudent(s2);

    std::cout << "Comparison by:\n";
    std::cout << "Name: " << compareName(s1, s2) << "\n";
    std::cout << "Math: " << compareMath(s1, s2) << "\n";
    std::cout << "Eng:  " << compareEng(s1, s2) << "\n";
    std::cout << "Hist: " << compareHist(s1, s2) << "\n";
    std::cout << "Avg:  " << compareAvg(s1, s2) << "\n";
    return 0;
}
