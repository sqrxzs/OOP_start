#include <iostream>
#include <fstream>
#include "Contact.h"

class PhoneBook {
private:
    Contact** contacts; // ������ ���������� �� ��������
    int size; // ���������� ���������
    int capacity; // ����������� �������

    // ����� ���������� ������� �������
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
    // �����������
    PhoneBook() {
        size = 0;
        capacity = 10; // ��������� �����������
        contacts = new Contact * [capacity];
    }

    // ����������
    ~PhoneBook() {
        for (int i = 0; i < size; ++i) {
            delete contacts[i]; // ����������� ������ �������
        }
        delete[] contacts; // ����������� ������ ����������
    }

    // ����� ��� ���������� ������ ��������
    void addContact(const char* name, const char* home, const char* work, const char* mobile, const char* info) {
        if (size == capacity) {
            resize(); // ����������� ������ �������, ���� ����������
        }
        contacts[size++] = new Contact(name, home, work, mobile, info); // ������� ����� �������
    }

    // ����� ��� �������� �������� �� ���
    void deleteContact(const char* name) {
        for (int i = 0; i < size; ++i) {
            if (strcmp(contacts[i]->getName(), name) == 0) {
                delete contacts[i]; // ������� �������
                contacts[i] = contacts[size - 1]; // ���������� ��������� �������
                --size; // ��������� ������
                std::cout << "������� " << name << " ������.\n";
                return;
            }
        }
        std::cout << "������� �� ������.\n";
    }

    // ����� ��� ������ �������� �� ���
    void searchContact(const char* name) const {
        for (int i = 0; i < size; ++i) {
            if (strcmp(contacts[i]->getName(), name) == 0) {
                contacts[i]->display(); // ���������� ���������� � ��������
                return;
            }
        }
        std::cout << "������� �� ������.\n";
    }

    // ����� ��� ����������� ���� ���������
    void displayAll() const {
        if (size == 0) {
            std::cout << "���������� ����� �����.\n";
            return;
        }
        for (int i = 0; i < size; ++i) {
            contacts[i]->display();
        }
    }

    // ����� ��� ���������� ���������� � ����
    void saveToFile(const char* filename) const {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "������ �������� ����� ��� ������.\n";
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
        std::cout << "������ ������� ���������.\n";
    }

    // ����� ��� �������� ���������� �� �����
    void loadFromFile(const char* filename) {
        std::ifstream inFile(filename);
        if (!inFile) {
            std::cerr << "������ �������� ����� ��� ������.\n";
            return;
        }
        while (!inFile.eof()) {
            char name[100], home[15], work[15], mobile[15], info[50];
            inFile.getline(name, 100, ',');
            if (strlen(name) == 0) break; // �������� �� ������ ������
            inFile.getline(home, 15, ',');
            inFile.getline(work, 15, ',');
            inFile.getline(mobile, 15, ',');
            inFile.getline(info, 50);
            addContact(name, home, work, mobile, info);
        }
        inFile.close();
        std::cout << "������ ������� ���������.\n";
    }
};