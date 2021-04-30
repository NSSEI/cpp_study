#include <iostream>

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2);

int main()
{
	Point* p1 = new Point;
	Point* p2 = new Point;

	p1->xpos = 1;
	p1->ypos = 2;
	p2->xpos = 3;
	p2->ypos = 4;
	
	Point &p3 = PntAdder(*p1, *p2);

	std::cout << p3.xpos << ',' << p3.ypos << std::endl;
	return 0;
}

Point& PntAdder(const Point &p1, const Point &p2)
{
	Point *ptr = new Point;
	ptr->xpos = p1.xpos + p2.xpos;
	ptr->ypos = p1.ypos + p2.ypos;
	return *ptr;
}