#include <stdio.h>
#include <vector>

class Foo {
private:
public:
    int *x;
    Foo(int *a) {
        printf("def c\n");
        x = a;
    }
    Foo(const Foo &f) {
        printf("copy c\n");
        x = f.x;
    }
    Foo(const Foo &&f) {
        printf("move c\n");
        x = f.x;
    }
};

int main() {
    std::vector<Foo> v; // found in /usr/include/c++/15.2.1/bits
    int a = 10;
    int b = 20;
    // TODO: alloc array with new
    Foo f(&a);
    Foo g = f;
    //v.push_back(f);
    //printf("%d\n", *(v[0].x));
    //f.x = &b;
    //v.push_back(f);
    //printf("f: %d, v[0]: %d, v[1]: %d\n", *(f.x), *(v[0].x), *(v[1].x));
    return 0;
}
