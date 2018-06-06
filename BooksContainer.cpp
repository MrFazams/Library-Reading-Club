#include "BooksContainer.h"
#include "Author.h"



void BooksContainer::swap(int idx1, int idx2)
{
	Book temp = (*this)[idx1];
	(*this)[idx1] = (*this)[idx2];
	(*this)[idx2] = temp;
}

void BooksContainer::sort(bool(*compareBooks)(const Book &book1, const Book &book2))
{
	int size = getSize();
	for (int i = 1; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (compareBooks((*this)[i], (*this)[j])) swap(i, j);
		}
	}
}

BooksContainer BooksContainer::booksByAuthor(const Author & author)
{
	BooksContainer temp;
	int size = getSize();
	for (int i = 0; i < size; i++) {
		if (*(((*this)[i]).getAuthor()) == author) temp.insert((*this)[i]);
	}
	return temp;
}
