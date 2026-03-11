#include "Sort.h"

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cstring>
#include <stdarg.h>

Sort::Sort(long long int size) {
    this->size = size;
    this->a = (int *)malloc(size * sizeof(int));
}

Sort::Sort(int size, int min, int max) : Sort(size) {
    int d = max - min;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        this->a[i] = (rand()%d) + min + 1;
    }
}

// TODO:
Sort::Sort(int a[]) {
}

Sort::Sort(int *a, int size) : Sort(size) {
    memcpy(this->a, a, size * sizeof(int));
}

Sort::Sort(int size, ...) : Sort((long long int)size) {
    va_list args;
    va_start(args, size);
    for (int i = 0; i < size; i++) {
        this->a[i] = va_arg(args, int);
    }
    va_end(args);
}

Sort::Sort(char *s) {
    char *ss = s;
    int size = 1;


    for (; *s != '\0'; s++) {
        if (*s == ',') size++;
    }
    s = ss;
    char *p = strtok(s, ",");

    this->size = size;
    this->a = (int *)malloc(size * sizeof(int));

    for (int i = 0; p; i++) {
        a[i] = atoi(p);
        p = strtok(NULL, ",");
    }
}

void Sort::InsertSort(bool ascendent) {
}
void Sort::QuickSort(bool ascendent) {
}
void Sort::BubbleSort(bool ascendent) {
    for (int i = 0; i < this->size-1; i++) {
        for (int j = i+1; j < this->size; j++) {
            if (ascendent && a[i] > a[j] || !ascendent && a[i] < a[j]) {
                int aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    }
}

void Sort::Print() {
    for (int i = 0; i < this->size; i++) {
        std::cout << this->a[i] << " ";
    }
    std::cout << "\n";
}
int Sort::GetElementsCount() {
    return this->size;
}
int Sort::GetElementFromIndex(int index) {
    return this->a[index];
}
