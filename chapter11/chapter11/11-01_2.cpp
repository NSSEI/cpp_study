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
	Book(const Book &ref)
		:price(ref.price)
	{
		int len1 = strlen(ref.title) + 1;
		int len2 = strlen(ref.isbn) + 1;
		title = new char[len1];
		isbn = new char[len2];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
	}
	Book& operator=(const Book &ref)
	{
		delete[] title;
		delete[] isbn;

		int len1 = strlen(ref.title) + 1;
		int len2 = strlen(ref.isbn) + 1;
		title = new char[len1];
		isbn = new char[len2];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
		price = ref.price;
		return *this;
	}
	void ShowBookInfo()
	{
		std::cout << "Title : " << title << std::endl;
		std::cout << "ISBN : " << isbn << std::endl;
		std::cout << "Price : " << price << std::endl;
	}
	~Book()
	{
		delete[] title;
		delete[] isbn;
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
	EBook(const EBook &ref)
		:Book(ref)
	{
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}
	EBook& operator=(const EBook &ref)
	{
		Book::operator=(ref);
		delete[] DRMKey;
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
		return *this;
	}
	void ShowBookInfo()
	{
		Book::ShowBookInfo();
		std::cout << "인증키 : " << DRMKey << std::endl;
	}
	~EBook()
	{
		delete[] DRMKey;
	}
};

int main()
{
	EBook ebook1((char*)"좋은 C++", (char*)"555-12345-890-0", 20000, (char*)"fasvsdsd0sf");
	EBook ebook2 = ebook1;
	ebook2.ShowBookInfo();
	std::cout << std::endl;
	std::cout << std::endl;
	EBook ebook3((char*)"좋은 C++ ebook", (char*)"555-12345-890-1", 10000, (char*)"fdx9w0i8kiw");
	ebook3 = ebook2;
	ebook3.ShowBookInfo();
	return 0;
}