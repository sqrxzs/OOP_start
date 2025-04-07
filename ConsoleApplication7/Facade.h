#include <iostream>
using namespace std;

class CPU {
public:
    void start() { cout << "��������� �������" << endl; }
};

class Memory {
public:
    void load() { cout << "������ ���������" << endl; }
};

class GraphicsCard {
public:
    void init() { cout << "���������� ����������������" << endl; }
};

class Computer {
    CPU cpu;
    Memory memory;
    GraphicsCard gpu;
public:
    void start() {
        cpu.start();
        memory.load();
        gpu.init();
        cout << "��������� ����� � ������" << endl;
    }
};