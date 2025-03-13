#pragma once
#include <iostream>

using namespace std;
class Prototype
{
public:
    virtual Prototype* clone() const = 0;
    virtual void showConfiguration() const = 0;
    virtual ~Prototype() {}
};

class GamingComputer : public Prototype {
private:
    string gpu;
    string cpu;
public:
    GamingComputer(const string& gpu, const string& cpu) : gpu(gpu), cpu(cpu) {}
    Prototype* clone() const override {
        return new GamingComputer(*this);
    }
    void showConfiguration() const override {
        cout << "Gaming Computer - GPU: " << gpu << ", CPU: " << cpu << endl;
    }
};

class OfficeComputer : public Prototype {
private:
    string os;
    string ram;
public:
    OfficeComputer(const string& os, const string& ram) : os(os), ram(ram) {}
    Prototype* clone() const override {
        return new OfficeComputer(*this);
    }
    void showConfiguration() const override {
        cout << "Office Computer - OS: " << os << ", RAM: " << ram << endl;
    }
};


