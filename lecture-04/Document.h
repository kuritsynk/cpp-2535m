#pragma once
#include <iostream>

//  ласс Document - абстрактный класс, т.к. содержит чистые виртуальные функции
// Ќельз€ создавать экземпл€ры абстрактных классов - ошибка компил€ции
class Document {

public:
	// чистый виртуальный метод (функци€)
	virtual int getDocumentType() = 0;

	virtual void save(std::ostream& os) = 0;

	virtual void load(std::istream& is) = 0;
};