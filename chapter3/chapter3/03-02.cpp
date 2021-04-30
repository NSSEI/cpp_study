#include <iostream>
#include "03-02.h"

int main()
{
	Calculator cal;
	cal.Init();
	std::cout << cal.Add(3.2, 2.4) << std::endl;
	std::cout << cal.Div(3.5, 1.7) << std::endl;
	std::cout << cal.Min(2.2, 1.5) << std::endl;
	std::cout << cal.Div(4.9, 1.2) << std::endl;
	cal.ShowOpCount();

	Printer pnt;
	pnt.SetString("Hello world");
	pnt.ShowString();

	pnt.SetString("c++");
	pnt.ShowString();

	return 0;
}