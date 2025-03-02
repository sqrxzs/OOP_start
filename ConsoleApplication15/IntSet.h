#pragma once
#include <iostream>
class IntSet {
private:
    int* arr;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    bool contains(int value) const {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                return true;
            }
        }
        return false;
    }

public:
    IntSet() : size(0), capacity(10) {
        arr = new int[capacity];
    }

    IntSet(int* elements, int n) : size(0), capacity(n * 2) {
        arr = new int[capacity];
        for (int i = 0; i < n; i++) {
            if (!contains(elements[i])) {
                arr[size++] = elements[i];  // добавляем элементы без повторов
            }
        }
    }

    IntSet(const IntSet& other) {
        size = other.size;
        capacity = other.capacity;
        arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    ~IntSet() {
        delete[] arr;
    }

    IntSet& operator=(const IntSet& other) {
        if (this != &other) {
            delete[] arr;
            size = other.size;
            capacity = other.capacity;
            arr = new int[capacity];
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    bool operator==(const IntSet& other) const {
        if (size != other.size) return false;
        for (int i = 0; i < size; i++) {
            if (!other.contains(arr[i])) {
                return false;
            }
        }
        return true;
    }

    IntSet& operator+=(int value) {
        if (!contains(value)) {
            if (size >= capacity) {
                resize();
            }
            arr[size++] = value;
        }
        return *this;
    }

    IntSet operator+(int value) const {
        IntSet result = *this;
        result += value;
        return result;
    }

    IntSet& operator-=(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                arr[i] = arr[size - 1];
                size--;
                break;
            }
        }
        return *this;
    }

    IntSet operator-(int value) const {
        IntSet result = *this;
        result -= value;
        return result;
    }

    IntSet operator+(const IntSet& other) const {
        IntSet result = *this;
        for (int i = 0; i < other.size; i++) {
            result += other.arr[i];
        }
        return result;
    }

    IntSet& operator+=(const IntSet& other) {
        for (int i = 0; i < other.size; i++) {
            *this += other.arr[i];
        }
        return *this;
    }

    IntSet operator-(const IntSet& other) const {
        IntSet result = *this;
        for (int i = 0; i < other.size; i++) {
            result -= other.arr[i];
        }
        return result;
    }
    IntSet operator*(const IntSet& other) const {
        IntSet result;
        for (int i = 0; i < size; i++) {
            if (other.contains(arr[i])) {
                result += arr[i];
            }
        }
        return result;
    }

    IntSet& operator*=(const IntSet& other) {
        IntSet result;
        for (int i = 0; i < size; i++) {
            if (other.contains(arr[i])) {
                result += arr[i];
            }
        }
        *this = result;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const IntSet& s) {
        for (int i = 0; i < s.size; i++) {
            os << s.arr[i] << " ";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, IntSet& s) {
        int value;
        while (is >> value) {
            s += value;
        }
        return is;
    }
};
