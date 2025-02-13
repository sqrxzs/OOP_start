#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>


class Contact {
public:
    char* name; // ������������ �������� ���
    char homePhone[15];
    char workPhone[15];
    char mobilePhone[15];
    char additionalInfo[50];


    // �����������
    Contact(const char* name, const char* homePhone, const char* workPhone, const char* mobilePhone, const char* additionalInfo) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        strncpy(this->homePhone, homePhone, sizeof(this->homePhone));
        strncpy(this->workPhone, workPhone, sizeof(this->workPhone));
        strncpy(this->mobilePhone, mobilePhone, sizeof(this->mobilePhone));
        strncpy(this->additionalInfo, additionalInfo, sizeof(this->additionalInfo));
    }

    // ����������
    ~Contact() {
        delete[] name; // ����������� ������, ���������� ��� ���
    }

    // ����� ��� ����������� ���������� �� ��������
    void display() const {
        std::cout << "���: " << name << ", �������� �������: " << homePhone
            << ", ������� �������: " << workPhone << ", ��������� �������: " << mobilePhone
            << ", ���. ����������: " << additionalInfo << std::endl;
    }

    // ����� ��� ��������� ���
    const char* getName() const {
        return name;
    }
};

