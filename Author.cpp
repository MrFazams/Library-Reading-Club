#include "Author.h"



Author::Author()
{
}

Author::Author(const char * name, int age, const char * nationality) : Reader(name, age, nationality)
{
}

Author::Author(const Author & a)
{
	*this = a;
}

Author::~Author()
{
}

void Author::writeBook(Book & b)
{
	writtenBooks.insert(b);
}

int Author::getWrittenBooksCount() const
{
	return writtenBooks.getSize();
}

int Author::getWritingRank() const
{
	int pages = 0;
	for (int i = 0; i < writtenBooks.getSize(); i++) {
		pages += writtenBooks[i].getPageCount();
	}
	return pages;
}

const Author & Author::operator=(const Author & a)
{
	Reader::operator=(a);
	this->writtenBooks = a.writtenBooks;
	return *this;
}
