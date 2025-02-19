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
		cout << "������� ����: " << userElevator;
	}
	void ElevatorWork() {
		cout << "\n";
		ElevatorFloor();
		cout << "\n������� 1 ��� �� ��� � 0 ��� �� ���� ";
		cin >> enabling;
		switch (enabling)
		{
		case 1:
			cout << "�� ��� ����. \n"
				"�������� ���������� �������� : \n"
				"������� 1 ��� �� ��������� �������� �� ����:\n"
				"������� 2 ��� �� ������� ����:\n";
			cin >> userElevator;
			if (userElevator == 1) {
				cout << "���� ��������!";
				ElevatorWork();
			}
			else if (userElevator == 2) {
				cout << "�� ����� ����� �� ����������: ";
				cin >> userElevator;
				cout << "���� ������ �� " << userElevator << " ����";
				ElevatorWork();
			}
			else {
				cout << "���� �� ��������!";
			}
			break;
		case 0:
			cout << "���� ����!";
			ElevatorWork();
			break;
		}
	}
	
};

