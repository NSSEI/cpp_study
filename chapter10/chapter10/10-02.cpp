#include <iostream>

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	void ShowPosition() const
	{
		std::cout << "[" << xpos << ", " << ypos << ']' << std::endl;
	}
	Point operator-()
	{
		Point p(-xpos, -ypos);
		return p;
	}
	Point operator~()
	{
		Point p(ypos, xpos);
		return p;
	}
};


int main()
{
	Point pos1(1, 2);
	Point pos2 = -pos1;
	Point pos3 = ~pos1;

	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}