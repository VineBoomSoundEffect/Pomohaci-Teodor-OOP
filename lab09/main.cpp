#include <stdio.h>
//#include <stdlib.h>

#define CAP 100

template<class KEY, class VALUE> //merge si class in loc de typename
class Map {
private:
    KEY keys[CAP];
    VALUE values[CAP];
    int index;
public:
    Map() {
        index = 0;
    }
    VALUE &operator[](KEY key) {
        for (int i = 0; i < index; i++) {
            if (keys[i] == key) {
                return values[i];
            }
        }
        index++;
        keys[index-1] = key;
        return values[index-1];
    }
    Map *begin() {
        :
    }
};

// urmatorarele metode trebuie implementate:
// begin(), end(), MyIterator$ operator++(), operator!=(), operator*()
// operatorii unari sunt fara argumente

int main()
{
    Map<int, const char *> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    //for (int i = 0; i < 3; i++) {
    //    printf("Index:%d, Value=%s\n", i, m[(i+1)*10]);
    //}
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
