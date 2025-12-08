#pragma once

#include "DocumentTypes.h"
#include "Passport.h"
#include "StudentId.h"

Document* createDocument(int documentType) {
	switch (documentType) {
	case PASSPORT: return new Passport();
	case STUDENT_ID: return new StudentId();
	default: throw "Неизвестный тип документа";
	};
}

