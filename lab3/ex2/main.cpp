#include <iostream>
#include "Canvas.h"

int main() {
    Canvas c(30,30);
    c.DrawRect(5, 5, 25, 25, '#');
    c.FillRect(10, 10, 20, 20, '$');
    c.DrawLine(0, 0, 25, 5, 'S');
    c.Print();
    c.Clear();
    return 0;
}
