#include <iostream>

#include "Author.h"
#include "Community.h"

using namespace std;



void testBook()
{
	Book a;
	Author dan("Dan Brown", 47, "American");
	Book b("Inferno", dan, THRILLER, 200, 2005, 19.99);
	Book c(b);
	cout << c;
	if (c == b) cout << "B and C are the same!\n\n";
	cout << a;
	cin >> a;
	cout << endl << a;
}

void testSet()
{
	BooksContainer b;
	Author dan("Dan Brown", 47, "American");
	Book i("Inferno", dan, THRILLER, 200, 2005, 19.99);
	b.insert(i);
	Book a;
	cin >> a;
	cout << endl;
	b.insert(a);
	b.print();
	b.remove(a);
	b.print();
	Book c(i);
	if (b.has(c)) cout << "Copy successful\n\n";
}

void testAuthor()
{
	Author dan("Dan Brown", 47, "American");
	Author a;
	Book bible("Bible", a, NOT_SPECIFIED, 2000, 0, 10);
	dan.readBook(bible);
	Book i("Inferno", dan, THRILLER, 200, 2005, 19.99);
	Book o("Origin", dan, THRILLER, 200, 2017, 19.99);
	dan.writeBook(i);
	dan.writeBook(o);
	cout << dan.getReadingRank() << endl << dan.getWritingRank() << endl;
}

void testCommunity()
{
	Community c;
	Author dan("Dan Brown", 47, "American");
	Author a;
	Reader b;
	Reader d;
	Book bible("Bible", a, NOT_SPECIFIED, 2000, 0, 10);
	Book i("Inferno", dan, THRILLER, 200, 2005, 19.99);
	Book o("Origin", dan, THRILLER, 200, 2017, 19.99);
	dan.readBook(bible);
	dan.writeBook(i);
	dan.writeBook(o);
	b.readBook(bible);
	b.readBook(o);
	b.readBook(i);
	d.readBook(i);
	c.insert(a);
	c.insert(dan);
	c.insert(b);
	c.insert(d);
	cout << c.getReadingRank() << endl;
}

int main()
{
	//testBook();
	//testSet();
	//testAuthor();
	//testCommunity();
	system("pause");
	return 0;
}