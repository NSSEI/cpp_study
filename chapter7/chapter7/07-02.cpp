#include <iostream>

class Rectangle
{
private:
	int height;
	int width;
public:
	Rectangle(int n1, int n2)
		:height(n1), width(n2) {}
	void ShowAreaInfo()
	{
		std::cout << "Area : " << height * width << std::endl;
	}
};

class Square : public Rectangle
{
public:
	Square(int n)
		:Rectangle(n, n) {}
};

int main()
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}