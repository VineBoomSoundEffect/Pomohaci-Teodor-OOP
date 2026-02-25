#include <iostream>
#include "NumberList.h"

int main() {
    NumberList *n = new NumberList();
    n->Init();
    n->Add(11);
    n->Add(44);
    n->Add(55);
    n->Add(33);
    n->Add(22);
    n->Print();
    n->Sort();
    n->Print();
    return 0;
}
