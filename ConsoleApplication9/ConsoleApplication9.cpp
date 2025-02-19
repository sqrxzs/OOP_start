#include <iostream>
#include "Elevator.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	
	Elevator elevator(1,1,1,1);
	elevator.ElevatorWork();
}