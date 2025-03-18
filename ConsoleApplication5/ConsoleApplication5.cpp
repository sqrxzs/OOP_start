#include <iostream>
#include "CharStack.h"

using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    CharStack myStack(5);

    myStack.push('A');
    myStack.push('B');
    myStack.push('C');

    cout << "Количество символов в стеке: " << myStack.count() << endl;
    cout << "Верхний символ: " << myStack.peek() << endl;

    myStack.pop();
    cout << "Верхний символ после выталкивания: " << myStack.peek() << endl;

    myStack.clear();
    cout << "Стек очищен. Пустой ли стек? " << (myStack.isEmpty() ? "Да" : "Нет") << endl;

    return 0;
}
