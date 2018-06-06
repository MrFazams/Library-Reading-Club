#ifndef BOOKSCONTAINER_H
#define BOOKSCONTAINER_H

#include "Book.h"
#include "Set.h"

class BooksContainer : public Set<Book>
{

	void swap(int idx1, int idx2);

public:

	void sort(bool(*compareBooks)(const Book & book1, const Book & book2));
	BooksContainer booksByAuthor(const Author & author);

};

#endif BOOKSCONTAINER_H