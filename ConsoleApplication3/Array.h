#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    T* data;
    int size;
    int capacity;
    int grow;

public:
    Array(int initialSize = 10, int growSize = 10)
        : size(0), capacity(initialSize), grow(growSize) {
        data = new T[capacity];
    }

    ~Array() {
        delete[] data;
    }

    int GetSize() const {
        return size;
    }

    void SetSize(int newSize, int growSize = 1) {
        if (newSize > capacity) {
            capacity = newSize + growSize - 1;
            T* newData = new T[capacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        size = newSize < size ? newSize : size;
    }

    int GetUpperBound() const {
        return size > 0 ? size - 1 : -1;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    void FreeExtra() {
        if (size < capacity) {
            capacity = size;
            T* newData = new T[capacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
    }

    void RemoveAll() {
        size = 0;
    }

    T GetAt(int index) const {
        return data[index];
    }

    void SetAt(int index, T value) {
        if (index < size) {
            data[index] = value;
        }
    }

    T& operator[](int index) {
        return data[index];
    }

    void Add(const T& value) {
        if (size >= capacity) {
            SetSize(capacity + grow);
        }
        data[size++] = value;
    }

    Array<T> Append(const Array<T>& other) {
        Array<T> result(size + other.size);
        for (int i = 0; i < size; ++i) {
            result.Add(data[i]);
        }
        for (int i = 0; i < other.size; ++i) {
            result.Add(other.data[i]);
        }
        return result;
    }

    Array<T>& operator=(const Array<T>& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    T* GetData() {
        return data;
    }

    void InsertAt(int index, const T& value) {
        if (size >= capacity) {
            SetSize(capacity + grow);
        }
        for (int i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    void RemoveAt(int index) {
        if (index < size) {
            for (int i = index; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            size--;
        }
    }
};