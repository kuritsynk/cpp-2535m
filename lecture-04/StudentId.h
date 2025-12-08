#pragma once
#include "Document.h"
class StudentId : public Document {

public:
	int getDocumentType();

	void save(std::ostream& os);

	void load(std::istream& is);

};

