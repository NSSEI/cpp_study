#include <iostream>

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void ShowPosition() const
	{
		std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
	}
};

template <typename T>
void SwapData(T& p1, T& p2)
{
	T tmp = p1;
	p1 = p2;
	p2 = tmp;
}

template <typename T>
T SumArray(T arr[], int len)
{
	T sum = (T)0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

int main()
{
	Point p1(1, 2);
	Point p2(3, 4);
	SwapData(p1, p2);
	p1.ShowPosition();
	p2.ShowPosition();

	int arr1[] = { 1, 2, 3 };
	std::cout << SumArray(arr1, sizeof(arr1) / sizeof(int)) << std::endl;
	double arr2[] = { 1.1, 2.2, 3.3 };
	std::cout << SumArray(arr2, sizeof(arr2) / sizeof(double)) << std::endl;

	return 0;
}