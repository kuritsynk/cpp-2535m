#include <iostream>

// Три парадигмы ООП
// 1. Инкапсуляция - объединение данных и методов по работе с ними, защита данных от несанционированного доступа.
// 2. Наследование - повторное использование кода с сохранением интерфейса (см. следующую парадигму)
// 3. Полиморфизм - общий интерфейс для всей иерархии наследования.





class Vector {  // Vector - имя класса, имя нового типа данных
    // private: -- область видимости по умолчанию - доступ к полям в этой области имеют только методы класса и друзья класса


    // внутри класса объявляются члены класса: поля и методы

    // поля класса - переменные - члены класса

    int size; // размер вектора

    int* data; // данные вектора - массив из size элементов


public:





    // функции, объявленные внутри класса - это методы класса

    // Vector_print_Vector*(Vector* this) -- функция-метод класса с т.з. компилятора
    // void Vector_print_Vector*(Vector* this) { 
    //          for (int i = 0; i < this->size; ++i) {
    //             std::cout << this->data[i] << std::endl;
    //          }


    void print() {
        std::cout << "this=" << this << ", size=" << size << std::endl;

        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << std::endl;
        }

    }

    // Vector_setSize_Vector*_int
    void setSize(int size) {
        if (this->size != 0) {
            // освобождаем возможно ранее выделенную память
            delete[] data;
            this->size = 0;
            data = nullptr;
        }

        if (size == 0) {
            return;
        }

        data = new int[size];
        this->size = size;
    }

    int getSize();


private:


protected:

private:

public:


    // Конструктор - специальный метод класса, который служит для иниицализации его полей.
    // 1. Его имя = имя класса
    // 2. Он не возвращает результата (даже void)
    // Конструктор вызывается автоматически при объявлении экземпляра класса

    // Конструкторов может быть несколько (за счет механизма перегрузки).
    
    // Конструктор без входных параметров называется конструктором по умолчанию.
    Vector() 
        : data(nullptr), size(0)  // список инициализации, выполняется до тела конструктора
        // порядок инициализации определяется порядком объявления полей в классе
    {
        // тело конструктора по умолчанию
        std::cout << "Default constructor: this=" << this << std::endl;

    }

    // Конструтор, принимающий входные аргументы/параметры
    Vector(int size) : size(0), data(nullptr) {
        std::cout << "Constructor with argument: this=" << this << std::endl;
        setSize(size);
    }

    // Деструктор - специальный метод класса, который служит для освобождения ресурсов, выделенных классом при работе объекта.
    // 1. Имя метода = ~ + имя класса 
    // 2. Не возвращает результата
    // 3. Не принимает входных параметров

    // Деструктор вызывается автоматически при уничтожении объекта.
    // Деструктор может быть только один.
    ~Vector() {
        std::cout << "Destructor: this=" << this << std::endl;
        setSize(0);
    }




};

// printVector_Vector
//void printVector(Vector v) {
//    for (int i = 0; i < v.size; ++i) {
//        std::cout << v.data[i] << std::endl;
//    }
//}


// Определение метода класса Vector вне его объявления
int Vector::getSize() {
    return size;
}


int main()
{

    // Вектор из 5 элементов
    int size = 5;
    int* data = new int[size];

    // void printVector(int size, int* data);
    // int* sumVectors(int size1, int* data1, int size2, int* data2, int& size);

    Vector v1; // экземпляр класса Vector, объект 
    // Для объекта v1 вызывается конструктор по умолчанию

    {

        std::cout << "sizeof(Vector)=" << sizeof(Vector) << std::endl;

        Vector v2; // другой экземпляр класса Vector, объект (вызывается конструктор по умолчанию)

        // Объявлено два экземпляра класса Vector

        // v1.size = 5;  // чтобы обратиться к члену класса через объект нужно указать имя объекта + "." + имя члена класса -- доступа нет, т.к. поля в private области
        // v2.size = 10;

        // void printVector(Vector v);
        // Vector sumVectors(Vector v1, Vector v2);

        // printVector(v1); // printVector_Vector
        // printVector(v2);

        v1.setSize(5);
        v1.setSize(2);
        v2.setSize(10);

        std::cout << "&v1=" << &v1 << ", &v2=" << &v2 << std::endl;

        v1.print();
        v2.print();

        //Vector v3;
        //v3.setSize(5);
        //v3.print();

        {
            Vector v3(5);  // Vector_Vector_Vector*_int
            v3.print();

        } // Vector_~Vector_Vector*(&v3)

    } // Vector_~Vector_Vector*(&v2)

    delete[] data;


    // Оператор new 1) Выделяет память sizeof(Vector) байт, 2) Вызывает конструктор класса Vector, 3) Возвращает указатель на созданный объект
    Vector* vptr = new Vector(6); 

    // При работе с объектом через указатель, метод вызывается через имя указателя + "->" + имя метода
    vptr->print();

    std::cout << "vptr->size=" << vptr->getSize() << std::endl;

    // Оператор delete 1) Вызывает деструктор класса Vector, 2) Освобождает выделенную память
    delete vptr; 
    

} // Vector_~Vector_Vector*(&v1)