#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Sort.h"

int main() {
    Sort s1(10, 0, 50);
    s1.Print();
    s1.BubbleSort(true);
    s1.Print();
    s1.BubbleSort(false);
    s1.Print();

    int n = 5;
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) a[i] = i*i;
    Sort s2(a, n);
    s2.Print();

    Sort s3(5, 6,7,8,9,0);
    s3.Print();

    char str[12] = "45,56,67,78";
    Sort s4(str);
    s4.Print();
    return 0;
}
