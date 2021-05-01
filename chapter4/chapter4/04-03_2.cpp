#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void ShowPos(int pos)
	{
		switch (pos)
		{
		case CLERK:
			std::cout << "사원" << std::endl;
			break;
		case SENIOR:
			std::cout << "주임" << std::endl;
			break;
		case ASSIST:
			std::cout << "대리" << std::endl;
			break;
		case MANAGER:
			std::cout << "과장" << std::endl;
		}
	}
}
class NameCard
{
	char* name;
	char* comp;
	char* num;
	int pos;
	
public:
	NameCard(char* myname, char* mycomp, char* mynum, int posi)
	{
		pos = posi;
		int len1 = strlen(myname) + 1;
		int len2 = strlen(mycomp) + 1;
		int len3 = strlen(mynum) + 1;

		name = new char[len1];
		comp = new char[len2];
		num = new char[len3];

		strcpy(name, myname);
		strcpy(comp, mycomp);
		strcpy(num, mynum);
	}
	void ShowNameCardInfo()
	{
		std::cout << name << std::endl;
		std::cout << comp << std::endl;
		std::cout << num << std::endl;
		COMP_POS::ShowPos(pos);
	}
	~NameCard()
	{
		delete[] name;
		delete[] comp;
		delete[] num;
	}
};

int main()
{
	NameCard manClerk((char*)"Lee", (char*)"ABCEng", (char*)"010-1111-2222", COMP_POS::CLERK);
	manClerk.ShowNameCardInfo();
}