#include <iostream>

class Point
{
	int xpos, ypos;

public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
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
	void Init(int x, int y, int r)
	{
		mid.Init(x, y);
		rad = r;
	}
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
	void Init(int x1, int y1, int r1, int x2, int y2, int r2)
	{
		c1.Init(x1, y1, r1);
		c2.Init(x2, y2, r2);
	}
	void ShowRingInfo()
	{
		c1.ShowCircleInfo();
		c2.ShowCircleInfo();
	}
};

int main()
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}