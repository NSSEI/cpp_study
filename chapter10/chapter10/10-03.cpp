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
	friend std::ostream& operator<<(std::ostream&, const Point& pos);
	friend std::istream& operator>>(std::istream&, Point& pos);
};

std::ostream& operator<<(std::ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Point& pos)
{
	is >> pos.xpos >> pos.ypos;
	return is;
}

int main()
{
	Point pos1;
	std::cin >> pos1;
	std::cout << pos1;
	return 0;
}