#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

class Book
{
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(char* mytitle, char* myisbn, int myprice) :price(myprice)
	{
		title = new char[strlen(mytitle) + 1];
		isbn = new char[strlen(myisbn) + 1];
		strcpy(title, mytitle);
		strcpy(isbn, myisbn);
	}
	void ShowBookInfo()
	{
		std::cout << "Title : " << title << std::endl;
		std::cout << "ISBN : " << isbn << std::endl;
		std::cout << "Price : " << price << std::endl;
	}
};

class EBook :public Book
{
private:
	char* DRMKey;

public:
	EBook(char* mytitle, char* myisbn, int myprice, char* key)
		:Book(mytitle, myisbn, myprice)
	{
		DRMKey = new char[strlen(key) + 1];
		strcpy(DRMKey, key);
	}
};

int main()
{
	Book book((char*)"좋은 C++", (char*)"555-12345-890-0", 20000);
	book.ShowBookInfo();
	std::cout << std::endl;
	EBook ebook((char*)"좋은 C++ ebook", (char*)"555-12345-890-1", 10000, (char*)"fdx9w0i8kiw");
	ebook.ShowBookInfo();
}