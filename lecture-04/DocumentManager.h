#pragma once
#include <iostream>
#include "Document.h"

class DocumentManager {

	Document** docs;
	int count;

public:

	DocumentManager& addDoc(Document* doc);

	void load(std::istream& is);

	void save(std::ostream& os);
};