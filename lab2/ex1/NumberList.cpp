#include <iostream>
#include "NumberList.h"

void NumberList::Init() {
    this->count = 0;
}
bool NumberList::Add(int x) {
    if(count >= 10) return false;
    this->numbers[count] = x;
    count++;
    return true;
}

void NumberList::Sort() {
    int min;
    int aux;
    for (int i=0;i<this->count-1;i++) {
        min = i;
            for (int j=i+1;j<this->count;j++){
            if (this->numbers[min] > this->numbers[j]) {
                min = j;
            }
        }
        aux = this->numbers[i];
        this->numbers[i] = this->numbers[min];
        this->numbers[min] = aux;

    }
}
void NumberList::Print() {
    for (int i=0;i<this->count;i++) {
        std::cout << this->numbers[i] << " ";
    };
    std::cout << "\n";
}
