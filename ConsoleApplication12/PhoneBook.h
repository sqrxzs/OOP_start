#include <iostream>
#include <fstream>
#include "Contact.h"

class PhoneBook {
private:
    Contact** contacts; // Массив указателей на контакты
    int size; // Количество контактов
    int capacity; // Вместимость массива

    // Метод увеличения размера массива
    void resize() {
        capacity *= 2;
        Contact** newContacts = new Contact * [capacity];
        for (int i = 0; i < size; ++i) {
            newContacts[i] = contacts[i];
        }
        delete[] contacts;
        contacts = newContacts;
    }

public:
    // Конструктор
    PhoneBook() {
        size = 0;
        capacity = 10; // Начальная вместимость
        contacts = new Contact * [capacity];
    }

    // Деструктор
    ~PhoneBook() {
        for (int i = 0; i < size; ++i) {
            delete contacts[i]; // Освобождаем каждый контакт
        }
        delete[] contacts; // Освобождаем массив указателей
    }

    // Метод для добавления нового контакта
    void addContact(const char* name, const char* home, const char* work, const char* mobile, const char* info) {
        if (size == capacity) {
            resize(); // Увеличиваем размер массива, если необходимо
        }
        contacts[size++] = new Contact(name, home, work, mobile, info); // Создаем новый контакт
    }

    // Метод для удаления контакта по ФИО
    void deleteContact(const char* name) {
        for (int i = 0; i < size; ++i) {
            if (strcmp(contacts[i]->getName(), name) == 0) {
                delete contacts[i]; // Удаляем контакт
                contacts[i] = contacts[size - 1]; // Перемещаем последний контакт
                --size; // Уменьшаем размер
                std::cout << "Контакт " << name << " удален.\n";
                return;
            }
        }
        std::cout << "Контакт не найден.\n";
    }

    // Метод для поиска контакта по ФИО
    void searchContact(const char* name) const {
        for (int i = 0; i < size; ++i) {
            if (strcmp(contacts[i]->getName(), name) == 0) {
                contacts[i]->display(); // Отобразить информацию о контакте
                return;
            }
        }
        std::cout << "Контакт не найден.\n";
    }

    // Метод для отображения всех контактов
    void displayAll() const {
        if (size == 0) {
            std::cout << "Телефонная книга пуста.\n";
            return;
        }
        for (int i = 0; i < size; ++i) {
            contacts[i]->display();
        }
    }

    // Метод для сохранения информации в файл
    void saveToFile(const char* filename) const {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "Ошибка открытия файла для записи.\n";
            return;
        }
        for (int i = 0; i < size; ++i) {
            outFile << contacts[i]->getName() << ","
                << contacts[i]->homePhone << ","
                << contacts[i]->workPhone << ","
                << contacts[i]->mobilePhone << ","
                << contacts[i]->additionalInfo << "\n";
        }
        outFile.close();
        std::cout << "Данные успешно сохранены.\n";
    }

    // Метод для загрузки информации из файла
    void loadFromFile(const char* filename) {
        std::ifstream inFile(filename);
        if (!inFile) {
            std::cerr << "Ошибка открытия файла для чтения.\n";
            return;
        }
        while (!inFile.eof()) {
            char name[100], home[15], work[15], mobile[15], info[50];
            inFile.getline(name, 100, ',');
            if (strlen(name) == 0) break; // Проверка на пустую строку
            inFile.getline(home, 15, ',');
            inFile.getline(work, 15, ',');
            inFile.getline(mobile, 15, ',');
            inFile.getline(info, 50);
            addContact(name, home, work, mobile, info);
        }
        inFile.close();
        std::cout << "Данные успешно загружены.\n";
    }
};