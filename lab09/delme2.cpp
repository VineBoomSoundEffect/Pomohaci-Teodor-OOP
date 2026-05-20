#include <stdio.h>
#include <stdlib.h>
#include <vector>

class Foo {
private:
public:
    int x;
    int *ptr;
    Foo(int x) {
        printf("def c\n");
        this->x = x;
        this->ptr = &(this->x);
    }
};

int main() {
    int a = 10;
    Foo *f = new Foo(a);
    printf("%d\n", *(f->ptr));
    realloc(f, sizeof(Foo)*2);
    printf("%d\n", *(f->ptr));
    return 0;
}
