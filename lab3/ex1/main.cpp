#include <iostream>
#include "Math.h"

int main() {
    std::cout << Math::Add(2,4) << "\n";
    std::cout << Math::Add(2.5,4.5) << "\n";
    std::cout << Math::Add(2,3,4) << "\n";
    std::cout << Math::Add(2.5,3.5,4.5) << "\n";

    std::cout << Math::Mul(2,4) << "\n";
    std::cout << Math::Mul(2.5,4.5) << "\n";
    std::cout << Math::Mul(2,3,4) << "\n";
    std::cout << Math::Mul(2.5,3.5,4.5) << "\n";

    std::cout << Math::Add(3,3,4,10) << "\n";

    std::cout << Math::Add("hello ", "friend") << "\n";
    return 0;
}
