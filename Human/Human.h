#pragma once
#include <iostream>

using namespace std;
class Human
{
private:
	string* name;
	string* surname;
	string* surnameName;
	string age;
public:
	Human() {
		this->name = new string[150];
		cout << "Name: " << endl;
		cin >> *name;
		this->surname = new string[150];
		cout << "Surname: " << endl;
		cin >> *surname;
		this->surnameName = new string[150];
		cout << "Surname Name: " << endl;
		cin >> *surnameName;
		age = "21.09.2005";
	}
	~Human() {
		delete[] name, surname, surnameName;
	}
	string getName()const { return *name; }
	string getSurname()const { return *surname; }
	string getSurnameName()const { return *surnameName; }

	void setName(string* ppxName) {
		this->name = ppxName;
	}
	void setSurname(string* ppxSurname) {
		this->surname = ppxSurname;
	}
	void setSurnameName(string* ppxSurnameName) {
		this->surnameName = ppxSurnameName;
	}
	void printResult() {
		cout << "Name: " << *name << endl;
		cout << "Surname: " << *surname <<endl;
		cout << "Surame Name: " << *surnameName << endl;
		cout << "Age: " << age << endl;
		delete[]name, surname, surnameName;
	}	
};

