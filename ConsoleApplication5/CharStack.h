#pragma once
#include <iostream>
using namespace std;

class CharStack {
private:
    char* stack;
    int top;
    int capacity;

public:
    CharStack(int size) {
        capacity = size;
        stack = new char[capacity];
        top = -1;
    }

    ~CharStack() {
        delete[] stack;
    }

    void push(char c) {
        if (top < capacity - 1) {
            stack[++top] = c;
        }
        else {
            cout << "Стек полон!" << endl;
        }
    }

    char pop() {
        if (top >= 0) {
            return stack[top--];
        }
        else {
            cout << "Стек пуст!" << endl;
            return '\0';
        }
    }

    int count() {
        return top + 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void clear() {
        top = -1;
    }

    char peek() {
        if (top >= 0) {
            return stack[top];
        }
        else {
            cout << "Стек пуст!" << endl;
            return '\0';
        }
    }
};


