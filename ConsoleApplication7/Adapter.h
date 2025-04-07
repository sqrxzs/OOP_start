#pragma once
#include <iostream>

using namespace std;

class LegacyRectangle {
private:
    int width;
    int height;

public:
    void setWidth(int w) {
        width = w;
    }

    void setHeight(int h) {
        height = h;
    }

    int getArea() {
        return width * height;
    }

    void draw() {
        cout << "Рисуем прямоугольник с шириной " << width << " и высотой " << height << endl;
    }
};

class ModernShape {
public:
    virtual void resize(double factor) = 0;
    virtual void render() = 0;
    virtual ~ModernShape() {}
};

class RectangleAdapter : public ModernShape {
private:
    LegacyRectangle legacyRect;

public:
    void resize(double factor) override {
        int newWidth = static_cast<int>(legacyRect.getArea() * factor / legacyRect.getArea());
        int newHeight = static_cast<int>(legacyRect.getArea() * factor / newWidth);
        legacyRect.setWidth(newWidth);
        legacyRect.setHeight(newHeight);
    }

    void render() override {
        legacyRect.draw();
    }
};

