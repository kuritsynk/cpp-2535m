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


int main()
{

    

    Vector v1(5);
    {
        Vector v2; // конструктор по умолчанию
        v2 = v1; // v2.data = v1.data (оператор присваивания по умолчанию копирует данные побайтово)
    } // v2.~Vector() - уничтожается память, которой владеет v1
    v1.print();

    std::cout << "==================" << std::endl;

    {
        Vector v3 = v1; // конструктор копирования
    }
    v1.print();

    std::cout << "==================" << std::endl;

    Vector v2 = foo(v1);
    fooByPointer(&v1);
    fooByReference(v1);

    std::cout << "==================" << std::endl;


    Vector v3 = v1 + v2;
    // Vector v3(v1.operator+(v2)) - перегрузка оператора + при помощи метода
    // Vector v3(operator+(v1, v2)) - перегрузка оператор + при помощи функции

    Vector v4 = 5 * v3;
    // Vector v4(v3.operator*(int)) - перегрузка оператора * при помощи метода НЕ ПОДОЙДЕТ, т.к. левый оперантд - не Vector
    // Vector v4(operator+(int, Vector)) - перегрузка оператор * при помощи функции


    v4 = v3 * 5;

} // Vector_~Vector_Vector*(&v1)