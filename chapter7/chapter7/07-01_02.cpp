#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

class MyFriendInfo
{
private:
	char* name;
	int age;
public:
	MyFriendInfo(char* myname, int myage) : age(myage)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	void ShowMyFriendInfo()
	{
		std::cout << "이름 : " << name << std::endl;
		std::cout << "나이 : " << age << std::endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(char* myname, int myage, char* myaddr, char* myphone) : MyFriendInfo(myname, myage)
	{
		addr = new char[strlen(myaddr) + 1];
		phone = new char[strlen(myphone) + 1];

		strcpy(addr, myaddr);
		strcpy(phone, myphone);
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		std::cout << "주소 : " << addr << std::endl;
		std::cout << "phone : " << phone << std::endl << std::endl;
	}
};

int main()
{
	MyFriendDetailInfo mf((char*)"ccc", 3, (char*)"cc", (char*)"cccc-cccc");
	mf.ShowMyFriendDetailInfo();
	mf.ShowMyFriendInfo();
	return 0;
}