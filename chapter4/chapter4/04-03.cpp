#include <iostream>

class Point
{
	int xpos, ypos;

public:
	Point(int &x, int &y)
		:xpos(x), ypos(y) {}
	void ShowPointInfo() const
	{
		std::cout << xpos << ", " << ypos << std::endl;
	}
};

class Circle
{
	Point mid;
	int rad;

public:
	Circle(int &x, int &y, int &r)
		:mid(x, y), rad(r) {}
	void ShowCircleInfo() const
	{
		std::cout << "radius : " << rad << std::endl;
		mid.ShowPointInfo();
	}
};

class Ring
{
	Circle c1;
	Circle c2;

public:
	Ring(int x1, int y1, int r1, int x2, int y2, int r2)
		:c1(x1, y1, r1), c2(x2, y2, r2) {}
	void ShowRingInfo() const
	{
		c1.ShowCircleInfo();
		c2.ShowCircleInfo();
	}
};

int main()
{
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}