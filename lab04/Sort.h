#pragma once

class Sort
{
private:
    int *a;
    int size;
public:
    Sort(long long int size); // Pentru a nu scrie alocarea de memorie in fiecare functie sort; nu este int simplu ca sa nu fie ambiguu cu sort-ul variadic
    Sort(int size, int min, int max);
    Sort(int a[]);
    Sort(int *a, int size);
    Sort(int size, ...);
    Sort(char *s);

    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
