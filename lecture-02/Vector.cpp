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
            // ����������� �������� ����� ���������� ������

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

    // ����������� ��� ������� ���������� ���������� ������������� �� ���������.
    Vector::Vector()
        : data(nullptr), size(0)  // ������ �������������, ����������� �� ���� ������������
        // ������� ������������� ������������ �������� ���������� ����� � ������
    {
        // ���� ������������ �� ���������
        std::cout << "Default constructor: this=" << this << std::endl;

    }

    // ����������, ����������� ������� ���������/���������
    Vector::Vector(int size) : size(0), data(nullptr) {
        std::cout << "Constructor with argument: this=" << this << std::endl;
        setSize(size);
    }

    // ���������� - ����������� ����� ������, ������� ������ ��� ������������ ��������, ���������� ������� ��� ������ �������.
    // 1. ��� ������ = ~ + ��� ������ 
    // 2. �� ���������� ����������
    // 3. �� ��������� ������� ����������

    // ���������� ���������� ������������� ��� ����������� �������.
    // ���������� ����� ���� ������ ����.
    Vector::~Vector() {
        std::cout << "Destructor: this=" << this << std::endl;
        setSize(0);
    }


// ����������� ������ ������ Vector ��� ��� ����������
int Vector::getSize() const {
    return size;
}


Vector& Vector::operator =(const Vector& r) {
    if (this == &r) {
        // ���������� ������ ����
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
