#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>


class Contact {
public:
    char* name; // Динамическое хранение ФИО
    char homePhone[15];
    char workPhone[15];
    char mobilePhone[15];
    char additionalInfo[50];


    // Конструктор
    Contact(const char* name, const char* homePhone, const char* workPhone, const char* mobilePhone, const char* additionalInfo) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        strncpy(this->homePhone, homePhone, sizeof(this->homePhone));
        strncpy(this->workPhone, workPhone, sizeof(this->workPhone));
        strncpy(this->mobilePhone, mobilePhone, sizeof(this->mobilePhone));
        strncpy(this->additionalInfo, additionalInfo, sizeof(this->additionalInfo));
    }

    // Деструктор
    ~Contact() {
        delete[] name; // Освобождаем память, выделенную под имя
    }

    // Метод для отображения информации об абоненте
    void display() const {
        std::cout << "ФИО: " << name << ", Домашний телефон: " << homePhone
            << ", Рабочий телефон: " << workPhone << ", Мобильный телефон: " << mobilePhone
            << ", Доп. информация: " << additionalInfo << std::endl;
    }

    // Метод для получения ФИО
    const char* getName() const {
        return name;
    }
};

