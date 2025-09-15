#include <iostream> // подключение в стиле С++ (без расширения h). Все загружается в пространство имен std

// std - стандартное пространство имен




int foo() { // int foo()

	int y = 5;
	int x = 6;

	return 0;
} // y, x - уничтожаются


namespace cpp2532m {

	int foo() {
		return 2;

	}

	namespace lecture01 {
		int foo() {

			cpp2532m::foo();

			::foo(); // вызов версии из глобального пространства имен

			return 1;
		}
	}

}


// Перегрузка функций - механизм, позволяющий определять функции в обном пространстве имен,
// с одинаковым именем, отличающиеся сигнатурой (набором входных параметров)
int foo(int x) {  // int foo_int(int x)
	return x;
}

// Ошибка определения функции, которая отличается только результатом
// void foo(int x) {
// }


using namespace std;

int main()
{
	int k = foo(); // k = 0 вызывается функция из глобавльного пространства имен foo
	// sizeof(int) байт занимает k

	{
		int k1 = 5;
	} // k1 

	int array[5]; // занимает 5 * sizeof(int) байт


	int l = cpp2532m::foo(); // l=2 cpp2532m_foo

	
	int m = foo(3); // работает перегрузка фунции foo() из глобального пространства имен

	foo(3); // foo_int(3)

	int n = cpp2532m::lecture01::foo(); // n = 1


	std::cout // стандартный поток вывода
		<<    // оператор вывода в поток
		"k="  // левый операнд, результом является поток std::cout
		<<
		k
		<<
		std::endl; // объект завершения строки: перевод строки + команда для сброса буфера


	// Стандартный поток ввода - std::cin

	cout << "Enter a value for m: ";

	cin >> //  оператор чтения из потока
		m;

	cout << endl << "m=" << m << endl;
		

	// Для размещения объектов в динамической памяти применяется оператор new/delete

	int* kp = &k; // указатель kp на целое число равен адресу k

	int k1 = *kp; // k1 = k, звездочка - операция разыменования
	*kp = 666;    // k = 666, k1 = старое значение k


	int* arrayp = array; // 
	int* arrayp1 = &array[0]; // arrayp1=arrayp

	*arrayp = 5;
	// array[0] == 5
	// *arrayp == 5 - потому что arrayp ссылается на нулевой элемент array

	int first = array[0];
	int first1 = arrayp[0]; // first1 = first


	int* pa = new int; // 1) выдеяется sizeof(int) байт в динамической памяти, 2) возвращается указатель int* на эту область
	*pa = 10; // записали значение в выделенную память

	delete pa;

	int* pb = new int(5); 
	cout << "*pb=" << *pb << endl; // *pb=5
	delete pb;

	int* parr = new int[m]; // 1) выделяется память sizeof(int) * m, 2) возвращается указатель на нулевой элемент массива

	for (int i = 0; i < m; ++i) {
		cout << "parr[i]" << parr[i] << endl;
	}

	delete[] parr;



}

