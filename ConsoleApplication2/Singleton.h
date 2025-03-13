#pragma once
#include <iostream>

using namespace std;

class Singleton {
private:
    static Singleton* instance;
    Singleton() {
        cout << "Singleton instance created." << endl;
    }

public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage() const {
        cout << "This is a message from the Singleton instance." << endl;
    }
};
Singleton* Singleton::instance = nullptr;
