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

Number::Number(const char * value, int base) {
    this->value = (char *)malloc((strlen(value)+1) * sizeof(char));
    strcpy(this->value, value);
    this->base = base;
}

// TODO:
Number::Number(int value, int base) {
}
Number::~Number() {
    //free(this->value);
}

Number operator+(Number a, Number b) {
    int base = (a.base > b.base) ? a.base : b.base;
    int n = a.GetIntegerValue() + b.GetIntegerValue();
    Number nr(n, base);
    return nr;
}
Number operator-(Number a, Number b) {
    int base = (a.base > b.base) ? a.base : b.base;
    int n = a.GetIntegerValue() - b.GetIntegerValue();
    Number nr(n, base);
    return nr;
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
    printf("here\n");
}
void Number::operator--(int) { //postfix
    printf("there\n");
}

// TODO:
void Number::SwitchBase(int newBase) {
    printf("total_value: %d\n", this->GetIntegerValue());

    //char *newValue = new char[20];
    //int wholes = total_value / newBase;
    //int remainder = total_value % newBase;
    //printf("wholes: %d\n", wholes);
    //printf("remainder: %d\n", remainder);

    //for (int i = 0; i < wholes; i++) {

    //}
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
