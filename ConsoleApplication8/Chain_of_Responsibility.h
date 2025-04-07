#include <iostream>
#include <string>
using namespace std;

class Request {
public:
    string description;
    Request(string desc) : description(desc) {}
};

class SupportHandler {
protected:
    SupportHandler* nextHandler;
public:
    void setNextHandler(SupportHandler* handler) {
        nextHandler = handler;
    }
    virtual void handleRequest(Request request) = 0;
    virtual ~SupportHandler() {}
};

class JuniorSupport : public SupportHandler {
public:
    void handleRequest(Request request) override {
        if (request.description.find("���������") != string::npos) {
            cout << "������� ����������: � ���������, � �� ���� ������ ��� ��������.\n";
            if (nextHandler) nextHandler->handleRequest(request);
        }
        else {
            cout << "������� ����������: ����� ��������!\n";
        }
    }
};

class SeniorSupport : public SupportHandler {
public:
    void handleRequest(Request request) override {
        cout << "������� ����������: �������� ������� ������.\n";
    }
};
