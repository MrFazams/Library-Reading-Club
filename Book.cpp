#include "Book.h"
#include "Author.h"



Book::Book()
{
	this->title = NULL;
	setTitle("N/A");
	author = NULL;
	setGenre(NOT_SPECIFIED);
	setPageCount(0);
	setPublishDate(0);
	setPrice(0.0);
}

Book::Book(const char * title, const Author & author, const Genre genre, const int pageCount, const int publishDate, const double price)
{
	this->title = NULL;
	setTitle(title);
	const Author * temp = &author;
	setAuthor(temp);
	setGenre(genre);
	setPageCount(pageCount);
	setPublishDate(publishDate);
	setPrice(price);
}

Book::Book(const Book & b)
{
	this->title = NULL;
	*this = b;
}

Book::~Book()
{
	delete[] title;
}

const char * Book::getTitle() const
{
	return title;
}

const Author * Book::getAuthor() const
{
	return author;
}

const Genre Book::getGenre() const
{
	return genre;
}

const int Book::getPageCount() const
{
	return pageCount;
}

const int Book::getPublishDate() const
{
	return publishDate;
}

const double Book::getPrice() const
{
	return price;
}

void Book::setTitle(const char * title)
{
	delete[] this->title;
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
}

void Book::setAuthor(const Author * author)
{
	this->author = author;
}

void Book::setGenre(const Genre genre)
{
	this->genre = genre;
}

void Book::setPageCount(const int pageCount)
{
	this->pageCount = pageCount;
}

void Book::setPublishDate(const int publishDate)
{
	this->publishDate = publishDate;
}

void Book::setPrice(const double price)
{
	this->price = price;
}

void Book::print() const
{
	std::cout << *(this);
}

const Book & Book::operator=(const Book & b)
{
	this->setTitle(b.getTitle());
	this->setAuthor(b.getAuthor());
	this->setGenre(b.getGenre());
	this->setPageCount(b.getPageCount());
	this->setPublishDate(b.getPublishDate());
	this->setPrice(b.getPrice());
	return *this;
}

bool Book::operator==(const Book & b) const
{
	if (strcmp(this->getTitle(), b.getTitle()) != 0) return false;
	if (this->getAuthor() != NULL && b.getAuthor() != NULL) {
		if (*(this->getAuthor()) != *(b.getAuthor())) return false;
	}
	else if (this->getAuthor() != NULL || b.getAuthor() != NULL) return false;
	if (this->getGenre() != b.getGenre()) return false;
	if (this->getPageCount() != b.getPageCount()) return false;
	if (this->getPublishDate() != b.getPublishDate()) return false;
	if (this->getPrice() != b.getPrice()) return false;
	return true;
}

bool Book::operator<(const Book & b) const
{
	if (strcmp(this->getTitle(), b.getTitle()) < 0) return true;
	if (strcmp(this->getTitle(), b.getTitle()) == 0) {
		if (*(this->getAuthor()) < *(b.getAuthor())) return true;
		if (*(this->getAuthor()) == *(b.getAuthor())) {
			if (this->getPageCount() < b.getPageCount()) return true;
			if (this->getPageCount() == b.getPageCount()) {
				if (this->getPublishDate() < b.getPublishDate()) return true;
				if (this->getPublishDate() == b.getPublishDate()) {
					if (this->getPrice() < b.getPrice()) return true;
				}
			}
		}
	}
	return false;
}

bool Book::operator>(const Book & b) const
{
	return !(*this == b || *this < b);
}

bool Book::operator<=(const Book & b) const
{
	return *this == b || *this < b;
}

bool Book::operator>=(const Book & b) const
{
	return !(*this < b);
}

bool Book::operator!=(const Book & b) const
{
	return !(*this == b);
}

/*
Book::operator bool() const
{
	return !(this->title[0] == '\0' && this->pageCount == 0 && this->publishDate == 0 && this->author->getName()[0] == '\0' && this->price == 0);
}

bool Book::operator!() const
{
	return !(bool)(*this);
}
*/

std::istream & operator>>(std::istream & i, Book & b)
{
	char tempTitle[100] = { '\0' };
	int tempG;
	i >> tempTitle >> tempG >> b.pageCount >> b.publishDate >> b.price;
	b.setTitle(tempTitle);
	b.author = NULL;
	switch (tempG) {
	case 1: b.genre = FANTASY; break;
	case 2: b.genre = HORROR; break;
	case 3: b.genre = ROMANCE; break;
	case 4: b.genre = THRILLER; break;
	case 5: b.genre = HISTORY; break;
	case 6: b.genre = ADVENTURE; break;
	default: b.genre = NOT_SPECIFIED; break;
	}
	return i;
}

std::ostream & operator<<(std::ostream & o, const Book & b)
{
	char * temp = NULL;
	switch (b.genre) {
	case 1: temp = new char[8]; strcpy(temp, "Fantasy"); break;
	case 2: temp = new char[7]; strcpy(temp, "Horror"); break;
	case 3: temp = new char[8]; strcpy(temp, "Romance"); break;
	case 4: temp = new char[9]; strcpy(temp, "Thriller"); break;
	case 5: temp = new char[8]; strcpy(temp, "History"); break;
	case 6: temp = new char[10]; strcpy(temp, "Adventure"); break;
	default: temp = new char[14]; strcpy(temp, "Not specified"); break;
	}
	o << "Title: " << b.title;
	if (b.author == NULL) o << "\nAuthor: N/A";
	else o << "\nAuthor: " << b.author->getName();
	o << "\nGenre: " << temp
		<< "\nPages: " << b.pageCount << "\nPublish date: " << b.publishDate << "\nPrice: " << b.price << "\n\n";
	delete[] temp;
	return o;
}
