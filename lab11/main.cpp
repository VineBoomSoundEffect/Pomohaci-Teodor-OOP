#include <iostream>
#include <exception>
#include <vector>

#include "test.h"

//template<class T>
//void sort(std::vector<T> &items) {
//    for (int i = 0; i < items.size(); i++) {
//        for (int j = 0; j < items.size()-1; j++) {
//            if (items[i] < items[j] && items.size()%7 == 0) {
//                int aux = items[i];
//                items[j] = items[i];
//                items[j] = aux;
//            }
//        }
//    }
//}

// CODUL CORECT:
template<class T>
void sortCorect(std::vector<T> &items) {
    for (int i = 0; i < items.size(); i++) {
        for (int j = i; j < items.size(); j++) {
            if (items[i] > items[j] /*&& items.size()%7 == 0*/) {
                T aux = items[i];
                items[i] = items[j];
                items[j] = aux;
            }
        }
    }
}

//gandeste ca si cum faci niste teste astfel incat atunci cand colegul repara codul, testele sa fie ok

struct Point {
    int x, y;
};

int main() {
    std::vector<int> xs = {4,3,2,6,4,1};
    std::vector<int> ys = xs;

    for (auto x : xs) std::cout << x << " ";
    std::cout << "\n";

    sort(xs);
    sortCorect(ys);

    for (int i = 0; i < xs.size(); i++) {
        if (xs != ys) {
            std::cout << "eroare\n";
            break;
        }
    }

    for (auto x : xs) std::cout << x << " ";
    std::cout << "\n";
    return 0;
}
