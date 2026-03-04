//#include <stdlib.h>
#include <stdarg.h>
#include <cstring>
#include "Math.h"
int Math::Add(int x, int y) {
    return x+y;
}
int Math::Add(int x, int y, int z) {
    return x+y+z;
}
int Math::Add(double x, double y) {
    return x+y;
}
int Math::Add(double x, double y, double z) {
    return x+y+z;
}
int Math::Mul(int x, int y) {
    return x*y;
}
int Math::Mul(int x, int y, int z) {
    return x*y*z;
}
int Math::Mul(double x, double y) {
    return x*y;
}
int Math::Mul(double x, double y, double z) {
    return x*y*z;
}
int Math::Add(int count, ...) {
    int sum = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}
char* Math::Add(const char *s1, const char *s2) {
    if (s1 != nullptr && s2 != nullptr) {
        int length = strlen(s1) + strlen(s2) + 1;
        char *s = new char[length];
        strcpy(s, s1);
        strcat(s, s2);
        return s;
    }
    return nullptr;
}
