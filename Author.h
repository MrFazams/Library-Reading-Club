#ifndef AUTHOR_H
#define AUTHOR_H

#define _CRT_SECURE_NO_WARNINGS

#include "Reader.h"
#include "WritingRankable.h"

class Author : public Reader, public WritingRankable
{

	BooksContainer writtenBooks;

public:
	
	Author();
	Author(const char * name, int age, const char * nationality);
	Author(const Author & a);
	~Author();

	void writeBook(Book & b);
	int getWrittenBooksCount() const;
	int getWritingRank() const;

	const Author & operator=(const Author & a);

};

#endif AUTHOR_H