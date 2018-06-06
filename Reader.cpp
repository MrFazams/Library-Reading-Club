#include "Reader.h"



Reader::Reader()
{
}

Reader::Reader(const char * name, int age, const char * nationality) : Person(name, age, nationality)
{
}

Reader::Reader(const Reader & r)
{
	*this = r;
}

Reader::~Reader()
{
}

void Reader::readBook(Book & b)
{
	readBooks.insert(b);
}

int Reader::getReadBooksCount() const
{
	return readBooks.getSize();
}

int Reader::getReadingRank() const
{
	int pages = 0;
	for (int i = 0; i < readBooks.getSize(); i++) {
		pages += readBooks[i].getPageCount();
	}
	return pages;
}

const Reader & Reader::operator=(const Reader & r)
{
	Person::operator=(r);
	this->readBooks = r.readBooks;
	return *this;
}
