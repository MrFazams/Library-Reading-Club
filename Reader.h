#ifndef READER_H
#define READER_H

#include "ReadingRankable.h"
#include "Person.h"
#include "BooksContainer.h"

class Reader : public ReadingRankable, public Person
{
private:

	BooksContainer readBooks;

public:

	Reader();
	Reader(const char * name, int age, const char * nationality);
	Reader(const Reader & r);
	~Reader();

	void readBook(Book & b);
	int getReadBooksCount() const;
	int getReadingRank() const;

	const Reader & operator=(const Reader & r);

};

#endif