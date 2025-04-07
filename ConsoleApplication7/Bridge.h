#include <iostream>
#include <string>
using namespace std;

class Formatter {
public:
    virtual string format(string text) = 0;
    virtual ~Formatter() {}
};

class HTMLFormatter : public Formatter {
public:
    string format(string text) override {
        return "<html>" + text + "</html>";
    }
};

class MarkdownFormatter : public Formatter {
public:
    string format(string text) override {
        return "**" + text + "**";
    }
};

class TextEditor {
    Formatter* formatter;
public:
    TextEditor(Formatter* f) : formatter(f) {}
    void setFormatter(Formatter* f) { formatter = f; }
    void print(string text) {
        cout << formatter->format(text) << endl;
    }
};
