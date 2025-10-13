#include<iostream>
#include "Vector.h"

void Vector::print() {
        std::cout << "this=" << this << ", size=" << size << std::endl;

        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << std::endl;
        }

    }

    // Vector_setSize_Vector*_int
    void Vector::setSize(int size) {
        if (this->size != 0) {
            // освобождаем возможно ранее выделенную память

            std::cout << "Delete data" << data << std::endl;

            delete[] data;
            this->size = 0;
            data = nullptr;
        }

        if (size == 0) {
            return;
        }

        data = new int[size];
        this->size = size;

        std::cout << "Allocate data" << data << std::endl;
    }

    // Конструктор без входных параметров называется конструктором по умолчанию.
    Vector::Vector()
        : data(nullptr), size(0)  // список инициализации, выполняется до тела конструктора
        // порядок инициализации определяется порядком объявления полей в классе
    {
        // тело конструктора по умолчанию
        std::cout << "Default constructor: this=" << this << std::endl;

    }

    // Конструтор, принимающий входные аргументы/параметры
    Vector::Vector(int size) : size(0), data(nullptr) {
        std::cout << "Constructor with argument: this=" << this << std::endl;
        setSize(size);
    }

    // Деструктор - специальный метод класса, который служит для освобождения ресурсов, выделенных классом при работе объекта.
    // 1. Имя метода = ~ + имя класса 
    // 2. Не возвращает результата
    // 3. Не принимает входных параметров

    // Деструктор вызывается автоматически при уничтожении объекта.
    // Деструктор может быть только один.
    Vector::~Vector() {
        std::cout << "Destructor: this=" << this << std::endl;
        setSize(0);
    }


// Определение метода класса Vector вне его объявления
int Vector::getSize() const {
    return size;
}


Vector& Vector::operator =(const Vector& r) {
    if (this == &r) {
        // присвоение самому себе
        return *this;
    }
    
    this->setSize(r.size);
    for (int i = 0; i < size; ++i) {
        data[i] = r.data[i];
    }
    return *this;
}

Vector::Vector(const Vector& src) : size(0), data(nullptr) {
    std::cout << "Copy Constructor: this=" << this << std::endl;
    setSize(src.size);
    for (int i = 0; i < size; ++i) {
        data[i] = src.data[i];
    }
 }


Vector Vector::operator+(const Vector& r) const {
    if (size != r.size) {
        throw "Wrong vector size";
    }


    Vector res(size);

    for (int i = 0; i < size; ++i) {
        res.data[i] = data[i] + r.data[i];
    }

    return res;
}

Vector operator*(int l, const Vector& r) {
    Vector res(r.size);

    for (int i = 0; i < r.getSize(); ++i) {
        res.data[i] = l * r.data[i];
    }

    return res;
}

Vector operator*(const Vector& l, int r) {
    return r * l;
}
