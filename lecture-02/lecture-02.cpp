#include <iostream>
#include "Vector.h"

// Три парадигмы ООП
// 1. Инкапсуляция - объединение данных и методов по работе с ними, защита данных от несанционированного доступа.
// 2. Наследование - повторное использование кода с сохранением интерфейса (см. следующую парадигму)
// 3. Полиморфизм - общий интерфейс для всей иерархии наследования.

using namespace std;


// При передаче параметров по значению создается копия объекта через конструктор копирования
Vector foo(Vector x) { // Vector x(v1)
    cout << "foo: x=" << &x << endl;
    x.print();
    return x;
} // x.~Vector()

void fooByPointer(Vector* x) {
    cout << "fooByPointer: x=" << x << endl;
}

void fooByReference(Vector& x) {
    cout << "fooByReference: x=" << &x << endl;
}


class Matrix {

    int rowCount;

    int colCount;

    Vector* cols;

public:

    Matrix() : rowCount(0), colCount(0), cols(nullptr) {

    }

    Matrix(int rowCount, int colCount) : rowCount(0), colCount(0), cols(nullptr) {

        cols = new Vector[colCount];
        for (int i = 0; i < colCount; ++i) {
            cols[i].setSize(rowCount);
        }
        this->rowCount = rowCount;
        this->colCount = colCount;
    }

    ~Matrix() {
        delete[] cols;
    }

    Matrix(const Matrix& src) : rowCount(0), colCount(0), cols(nullptr) {

        cols = new Vector[src.colCount];
        for (int i = 0; i < src.colCount; ++i) {
            cols[i] = src.cols[i]; // Vector::operator=
        }
        this->rowCount = src.rowCount;
        this->colCount = src.colCount;

    }

    friend Matrix operator+(const Matrix& l, const Matrix& r) {

        if (l.colCount != r.colCount
            || l.rowCount != r.rowCount) {
            throw "Incorrect matrix size";
        }

        Matrix res(l.rowCount, l.colCount);
        for (int i = 0; i < res.colCount; ++i) {
            res.cols[i] = l.cols[i] + r.cols[i];
        }

        return res;
    }

private:
    int& getData(int row, int column) {
        if (row < 0
            || row >= rowCount) {
            throw "Incorrect row";
        }
        if (column < 0
            || column >= colCount) {
            throw "Incorrect column";
        }
        return cols[column][row];
    }



    class Row;

public:
    Row operator[](int row) {
        if (row < 0
            || row >= rowCount) {
            throw "Incorrect row";
        }

        return Row(this, row);
    }

    class Row {

        Matrix* m;
        int row;

        

    public:

        Row(Matrix* m, int row) : m(m), row(row) {

        }

        int& operator[](int column) {
            return m->getData(row, column);
        }

    };


};



class A {

    int a;

public:

    A(int a) : a(a) {

    }

    int getA() const {
        return a;
    }

    void print() const {
        cout << "a= " << a << endl;
    }

};


// B - наследник класса А (или дочерний класс для А)
// A - базовый класс или родительский класс для B
class B : public A {

    // A base; -- все поля класса A

    int b;

public:
    // В конструкторе класса B вызывается конструтор базового класса A
    B(int a, int b) : A(a), b(b) {

    }


    // Метод A_getA_A* применимо и для объекта класса B
    /*int getA() const {
        return a;
    }*/

    int getB() const {
        return b;
    }

    void print() const {
        A::print();
        cout << "b=" << b << endl;
    }

};

void foo(A* aptr) {
    if (aptr->getA() > 0) {
        aptr->print();
    }
}

int main()
{

    A a(1);

    a.print(); // a=1

    foo(&a);

    B b(2, 3);
    b.getA();
    b.print(); // a=2 b=3

    foo(&b);
    

    //Vector v1(5);
    //{
    //    Vector v2; // конструктор по умолчанию
    //    v2 = v1; // v2.data = v1.data (оператор присваивания по умолчанию копирует данные побайтово)
    //} // v2.~Vector() - уничтожается память, которой владеет v1
    //v1.print();

    //std::cout << "==================" << std::endl;

    //{
    //    Vector v3 = v1; // конструктор копирования
    //}
    //v1.print();

    //std::cout << "==================" << std::endl;

    //Vector v2 = foo(v1);
    //fooByPointer(&v1);
    //fooByReference(v1);

    //std::cout << "==================" << std::endl;


    //Vector v3 = v1 + v2;
    //// Vector v3(v1.operator+(v2)) - перегрузка оператора + при помощи метода
    //// Vector v3(operator+(v1, v2)) - перегрузка оператор + при помощи функции

    //Vector v4 = 5 * v3;
    //// Vector v4(v3.operator*(int)) - перегрузка оператора * при помощи метода НЕ ПОДОЙДЕТ, т.к. левый оперантд - не Vector
    //// Vector v4(operator+(int, Vector)) - перегрузка оператор * при помощи функции


    //v4 = v3 * 5;

  
    //v4[1] = 888; // v4.data[1] = 888
    //cout << "v4[1]=" << v4[1] << endl;

    //const Vector& v5 = v4;
    //cout << "v5[1]=" << v5[1] << endl; // вызывается константная версия оператора []
    //// v5[1] = 666; - ошибка, нельзя писать в константу

    //std::cout << "==================" << std::endl;

    //Matrix m1(2, 3), m2(2, 3);
    //Matrix m3 = m1 + m2;

    // m3[1][2] = 5; // (m3.operator[](1)).operator[](2) -- ссылка на int

    //m3.operator[](1).operator[](2) = 5;
    //cout << "m3[1][2]=" << m3[1][2] << endl;

} // Vector_~Vector_Vector*(&v1)