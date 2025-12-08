#include "DocumentManager.h"
#include "DocumentFactory.h"

DocumentManager& DocumentManager::addDoc(Document* doc) {

	// добавляем указанный документ в массив docs

	return *this;

}

void DocumentManager::save(std::ostream& os) {

	os << count << std::endl;

	for (int i = 0; i < count; ++i) {
		os << docs[i]->getDocumentType() << std::endl;
		docs[i]->save(os);
	}

}

void DocumentManager::load(std::istream& is) {

	// очистить старый список
	delete[] docs;
	docs = nullptr;
	count = 0;

	is >> count;
	docs = new Document* [count];

	for (int i = 0; i < count; ++i) {
		int documentType;
		is >> documentType;

		docs[i] = createDocument(documentType);
		docs[i]->load(is);
	}


}