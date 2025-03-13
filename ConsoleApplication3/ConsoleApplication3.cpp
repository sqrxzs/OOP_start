#include <iostream>
#include "Array.h"

using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    Array<int> arr;

    arr.Add(10);
    arr.Add(20);
    arr.Add(30);
    arr.Add(40);

    cout << "Текущий размер: " << arr.GetSize() << endl;
    cout << "Верхняя граница: " << arr.GetUpperBound() << endl;

    for (int i = 0; i < arr.GetSize(); ++i) {
        cout << "Элемент в индексе " << i << ": " << arr[i] << endl;
    }

    arr.SetAt(2, 35);
    cout << "После установки индекса от 2 до 35:" << endl;
    for (int i = 0; i < arr.GetSize(); ++i) {
        cout << "Элемент в индексе " << i << ": " << arr[i] << endl;
    }

    arr.InsertAt(1, 25);
    cout << "После вставки 25 в индекс 1:" << endl;
    for (int i = 0; i < arr.GetSize(); ++i) {
        cout << "Элемент в индексе " << i << ": " << arr[i] << endl;
    }

    arr.RemoveAt(3);
    cout << "После удаления элемента с индексом 3:" << endl;
    for (int i = 0; i < arr.GetSize(); ++i) {
        cout << "Элемент в индексе " << i << ": " << arr[i] << endl;
    }

    arr.RemoveAll();
    cout << "После удаления всех элементов массив становится пустым? " << (arr.IsEmpty() ? "Да" : "Нет") << endl;

    return 0;
}