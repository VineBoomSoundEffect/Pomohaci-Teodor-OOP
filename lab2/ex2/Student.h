#pragma once

class Student {
private:
    char *name;
    float grade_math;
    float grade_eng;
    float grade_hist;
public:
    void SetName(const char *name);
    char *GetName();
    void SetGradeMath(float grade);
    float GetGradeMath();
    void SetGradeEng(float grade);
    float GetGradeEng();
    void SetGradeHist(float grade);
    float GetGradeHist();
    float GetAvg();
};
