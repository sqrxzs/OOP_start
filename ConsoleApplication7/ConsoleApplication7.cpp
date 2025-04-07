#include <iostream>
#include "Adapter.h"
#include "Bridge.h"
#include "Composite.h"
#include "Facade.h"
#include "Decorator.h"
using namespace std;




int main() {
    setlocale(LC_ALL, "rus");
    // Адаптер
    ModernShape* shape = new RectangleAdapter();
    shape->resize(2.5);
    shape->render();
    delete shape;

    // Декоратор
    BaseWidget* button = new ColorDecorator(new Button(), "красный");
    button->draw();
    delete button;

    // Фасад
    Computer comp;
    comp.start();

    // Компоновщик
    GroupOfObjects group;
    group.add(new Circle());
    group.add(new Rectangle());
    group.draw();

    // Мост
    TextEditor editor(new HTMLFormatter());
    editor.print("Привет мир");
    editor.setFormatter(new MarkdownFormatter());
    editor.print("Привет мир");

    return 0;
}