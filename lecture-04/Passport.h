#pragma once
#include "Document.h"

class Passport : public Document {

public:
	int getDocumentType();

	void save(std::ostream& os);

	void load(std::istream& is);


};

