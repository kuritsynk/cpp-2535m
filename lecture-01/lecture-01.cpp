#include <iostream>

int foo() { // int foo()
	return 0;
}


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


int main()
{
	int k = foo(); // k = 0 вызывается функция из глобавльного пространства имен foo

	int l = cpp2532m::foo(); // l=2 cpp2532m_foo

	
	int m = foo(3); // работает перегрузка фунции foo() из глобального пространства имен

	foo(3); // foo_int(3)

	int n = cpp2532m::lecture01::foo(); // n = 1
}

