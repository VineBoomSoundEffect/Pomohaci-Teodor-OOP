#include "Number.h"
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

int Number::GetIntegerValue() {
    const char digits[] = "0123456789ABCDEF";

    int total_value = 0;
    int digit_value;
    int pos = 0;
    int len = strlen(this->value);
    char digit;
    while (pos < len) {
        digit_value = 1;
        digit = this->value[len-pos-1];
        if ('0' <= digit && digit <= '9') digit -= '0';
        else if('A' <= digit && digit <= 'F') digit = (digit - 'A') + 10;
        for (int i = 0; i < pos; i++) {
            digit_value *= this->base;
        }
        digit_value *= digit;
        total_value += digit_value;
        pos++;
    }
    return total_value;
}

char *nr(int number, int base) {
    const char digits[] = "0123456789ABCDEF";
    char *value = new char[255];
    int len = 0;
    while (number > 0) {
        int remainder = number % base;
        for (int i = len; i > 0; i--) {
            value[i] = value[i-1];
        }
        len++;
        if (0 <= remainder && remainder <= 9) value[0] = remainder + '0';
        else if (10 <= remainder && remainder <= 15) value[0] = remainder - 10 + 'A';
        number /= base;
    }
    return value;
}

Number::Number(const char * value, int base) {
    this->value = (char *)malloc((strlen(value)+1) * sizeof(char));
    strcpy(this->value, value);
    this->base = base;
}

Number::Number(int number) {
    this->base = 10;
    this->value = nr(number, this->base);
}

Number::~Number() {
    //free(this->value);
}

Number operator+(Number a, Number b) {
    int base = (a.base > b.base) ? a.base : b.base;
    int n = a.GetIntegerValue() + b.GetIntegerValue();
    Number result(nr(n, base), base);
    return result;
}
Number operator-(Number a, Number b) {
    int base = (a.base > b.base) ? a.base : b.base;
    int n = a.GetIntegerValue() - b.GetIntegerValue();
    Number result(nr(n, base), base);
    return result;
}

char Number::operator[](int i) {
    return this->value[i];
}
bool Number::operator>(Number a) {
    return this->GetIntegerValue() > a.GetIntegerValue();
}
bool Number::operator<(Number a) {
    return this->GetIntegerValue() < a.GetIntegerValue();
}
bool Number::operator>=(Number a) {
    return this->GetIntegerValue() >= a.GetIntegerValue();
}
bool Number::operator<=(Number a) {
    return this->GetIntegerValue() <= a.GetIntegerValue();
}
bool Number::operator==(Number a) {
    return this->GetIntegerValue() == a.GetIntegerValue();
}
void Number::operator--() { //prefix
    this->value++;
}
void Number::operator--(int) { //postfix
    int i = 0;
    while (this->value[i+1] != '\0') i++;
    this->value[i] = '\0';
}

void Number::operator=(int number) {
    this->value = nr(number, this->base);
}
void Number::operator=(const char *value) {
    strcpy(this->value, value);
}
void Number::operator+=(Number a) {
    *this = *this + a;
}

void Number::SwitchBase(int newBase) {
    this->value = nr(this->GetIntegerValue(), newBase);
    this->base = newBase;
}
void Number::Print() {
   printf("%s\n",this->value);
}
int  Number::GetDigitsCount() {
    return strlen(this->value);
}
int  Number::GetBase() {
    return this->base;
}
