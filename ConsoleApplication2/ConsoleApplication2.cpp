#include <iostream>
#include "Prototype.h"
#include "Singleton.h"
int main() {
    GamingComputer gamingPC("NVIDIA RTX 3080", "Intel i9");
    OfficeComputer officePC("Windows 10", "16GB");

    Prototype* clonedGamingPC = gamingPC.clone();
    Prototype* clonedOfficePC = officePC.clone();

    clonedGamingPC->showConfiguration();
    clonedOfficePC->showConfiguration();

    delete clonedGamingPC;
    delete clonedOfficePC;


    Singleton* singleton1 = Singleton::getInstance();
    singleton1->showMessage();

    Singleton* singleton2 = Singleton::getInstance();
    singleton2->showMessage();

    if (singleton1 == singleton2) {
        cout << "Both instances are the same." << endl;
    }
    else {
        cout << "Instances are different." << endl;
    }

    return 0;
}