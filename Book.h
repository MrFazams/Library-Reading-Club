#ifndef BOOK_H
#define BOOK_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class Author;
enum Genre { NOT_SPECIFIED, FANTASY, HORROR, ROMANCE, THRILLER, HISTORY, ADVENTURE };

class Book
{

	char * title;
	const Author * author;
	Genre genre;
	int pageCount;
	int publishDate;
	double price;

public:

	Book();
	Book(const char * title, const Author & author, const Genre genre, const int pageCount, const int publishDate, const double price);
	Book(const Book & b);
	~Book();

	const char * getTitle() const;
	const Author * getAuthor() const;
	const Genre getGenre() const;
	const int getPageCount() const;
	const int getPublishDate() const;
	const double getPrice() const;

	void setTitle(const char * title);
	void setAuthor(const Author * author);
	void setGenre(const Genre genre);
	void setPageCount(const int pageCount);
	void setPublishDate(const int publishDate);
	void setPrice(const double price);

	void print() const;

	const Book & operator=(const Book & b); 
	bool operator==(const Book & b) const; 
	bool operator<(const Book & b) const;
	bool operator>(const Book & b) const;
	bool operator<=(const Book & b) const;
	bool operator>=(const Book & b) const;
	bool operator!=(const Book & b) const;
	//operator bool() const;
	//bool operator!() const;

	friend std::istream& operator>>(std::istream & i, Book & b);
	friend std::ostream& operator<<(std::ostream & o, const Book & b);

};

#endif BOOK_H