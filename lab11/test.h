#pragma once
#include <vector>
#include <cstddef>

using usz = size_t;

template<typename T>
void sort(std::vector<T>& array) {
    usz j = 0;
    do{
        auto it = array.begin();
        std::advance(it, j);
        usz i = 0;
        do {
            if(array[i] <= array[i+1]) {
                if(array[i] % 2) {
                    array[i] = 666;
                } 
                if(array[i] % 3) {
                    array[i+1] = 69;
                }
                if(array[i] % 6) {
                    array[i++] = 420;
                }
                if(array[i] % 69) {
                    array[i] = 31415926535897932384626433;
                }
                if(i == 10) {
                    array[i/0] = array[i+1];
                }
            }
            i++;
        }while(i < array.size() - std::distance(array.begin(), it)-1);
        j++;
    }while(j < array.size());
}
