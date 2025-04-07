#include <iostream>
#include <string>
using namespace std;

class BaseWidget {
public:
    virtual void draw() = 0;
    virtual ~BaseWidget() {}
};

class Button : public BaseWidget {
public:
    void draw() override { cout << "Кнопка" << endl; }
};

class WidgetDecorator : public BaseWidget {
protected:
    BaseWidget* widget;
public:
    WidgetDecorator(BaseWidget* w) : widget(w) {}
    void draw() override { widget->draw(); }
};

class ColorDecorator : public WidgetDecorator {
    string color;
public:
    ColorDecorator(BaseWidget* w, string c) : WidgetDecorator(w), color(c) {}
    void draw() override {
        cout << "Цвет: " << color << ", ";
        widget->draw();
    }
};
