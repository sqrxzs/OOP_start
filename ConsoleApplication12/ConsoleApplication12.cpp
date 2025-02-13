#include <iostream>
#include "Drob.h"
#include "PhoneBook.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int* num1 = new int(4);
	int* num2 = new int(2);
	Drob drod(num1, num2);
	drod.print();

    PhoneBook phoneBook;
    int choice;

    do {
        std::cout << "1. Добавить контакт\n"
            << "2. Удалить контакт\n"
            << "3. Искать контакт по ФИО\n"
            << "4. Показать всех абонентов\n"
            << "5. Сохранить информацию в файл\n"
            << "6. Загрузить информацию из файла\n"
            << "0. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        char name[100], home[15], work[15], mobile[15], info[50];

        switch (choice) {
        case 1:
            std::cout << "Введите ФИО: ";
            std::cin.ignore();
            std::cin.getline(name, 100);
            std::cout << "Введите домашний телефон: ";
            std::cin.getline(home, 15);
            std::cout << "Введите рабочий телефон: ";
            std::cin.getline(work, 15);
            std::cout << "Введите мобильный телефон: ";
            std::cin.getline(mobile, 15);
            std::cout << "Введите дополнительную информацию: ";
            std::cin.getline(info, 50);
            phoneBook.addContact(name, home, work, mobile, info);
            break;
        case 2:
            std::cout << "Введите ФИО для удаления: ";
            std::cin.ignore();
            std::cin.getline(name, 100);
            phoneBook.deleteContact(name);
            break;
        case 3:
            std::cout << "Введите ФИО для поиска: ";
            std::cin.ignore();
            std::cin.getline(name, 100);
            phoneBook.searchContact(name);
            break;
        case 4:
            phoneBook.displayAll();
            break;
        case 5:
            phoneBook.saveToFile("contacts.txt");
            break;
        case 6:
            phoneBook.loadFromFile("contacts.txt");
            break;
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Некорректный выбор. Повторите пожалуйста.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
