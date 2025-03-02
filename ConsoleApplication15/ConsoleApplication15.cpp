#include <iostream>
#include "IntSet.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    IntSet set1;
    set1 += 1;
    set1 += 2;
    set1 += 3;

    IntSet set2;
    set2 += 3;
    set2 += 4;
    set2 += 5;

    std::cout << "Массив 1: " << set1 << std::endl;
    std::cout << "Массив 2: " << set2 << std::endl;

    IntSet unionSet = set1 + set2;
    std::cout << "Массив объединений (Set1 + Set2): " << unionSet << std::endl;

    IntSet intersectionSet = set1 * set2;
    std::cout << "Массив пересечений (Set1 * Set2): " << intersectionSet << std::endl;

    set1 -= 2;  // Удалим элемент 2 из Set1
    std::cout << "Массив 1 после удаления 2: " << set1 << std::endl;

    IntSet differenceSet = set1 - set2;  // Set1 - Set2
    std::cout << "Массив различий (Set1 - Set2): " << differenceSet << std::endl;

    IntSet anotherSet;
    anotherSet += 1;
    anotherSet += 3;
    std::cout << "Ещё: " << anotherSet << std::endl;

    if (set1 == anotherSet) {
        std::cout << "Макссим 1 равен другому массиву." << std::endl;
    }
    else {
        std::cout << "Массив 1 не равен другому массиву." << std::endl;
    }

    return 0;
}
