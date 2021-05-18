#include <iostream>

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void SetPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPosition() const
	{
		std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
	}
};

template <typename T>
class SmartPtr
{
private:
	T* posptr;
public:
	SmartPtr(T* ptr) :posptr(ptr) {}
	Point& operator*() const { return *posptr; }
	Point* operator->() const { return posptr; }
	~SmartPtr() { delete posptr; }
};



int main()
{
	SmartPtr<Point> sptr1(new Point(1, 2));
	SmartPtr<Point> sptr2(new Point(3, 4));
	sptr1->ShowPosition();
	sptr2->ShowPosition();

	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr1->ShowPosition();
	sptr2->ShowPosition();
	return 0;
}