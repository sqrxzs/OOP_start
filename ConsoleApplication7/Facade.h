#include <iostream>
using namespace std;

class CPU {
public:
    void start() { cout << "Процессор запущен" << endl; }
};

class Memory {
public:
    void load() { cout << "Память загружена" << endl; }
};

class GraphicsCard {
public:
    void init() { cout << "Видеокарта инициализирована" << endl; }
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
        cout << "Компьютер готов к работе" << endl;
    }
};