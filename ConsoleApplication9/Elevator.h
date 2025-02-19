#pragma once
#include <iostream>

using namespace std;
class Elevator
{
private:
	int elevator;
	int enabling;
	int workElevator;
	int userElevator;
public:
	Elevator(int pEnabling, int pWorkElevator, int pUserElevator, int pElevator) {
		this->elevator = pElevator;
		this->enabling = pEnabling;
		this->workElevator = pWorkElevator;
		this->userElevator = pUserElevator;
	}
	
	void ElevatorFloor() {
		cout << "Текущий этаж: " << userElevator;
	}
	void ElevatorWork() {
		cout << "\n";
		ElevatorFloor();
		cout << "\nнажмите 1 что бы вкл и 0 что бы выкл ";
		cin >> enabling;
		switch (enabling)
		{
		case 1:
			cout << "Вы вкл лифт. \n"
				"Выберите дальнейшие действия : \n"
				"Нажмите 1 что бы проверить работает ли лифт:\n"
				"Нажмите 2 что бы вызвать лифт:\n";
			cin >> userElevator;
			if (userElevator == 1) {
				cout << "Лифт работает!";
				ElevatorWork();
			}
			else if (userElevator == 2) {
				cout << "На каком этаже вы находитесь: ";
				cin >> userElevator;
				cout << "Лифт вызван на " << userElevator << " этаж";
				ElevatorWork();
			}
			else {
				cout << "Лифт не работает!";
			}
			break;
		case 0:
			cout << "Лифт выкл!";
			ElevatorWork();
			break;
		}
	}
	
};

