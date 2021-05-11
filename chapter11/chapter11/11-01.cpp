#include <iostream>
#include <cstring>

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) :bullet(bnum) {}
	void Shut()
	{
		std::cout << "BBANG!" << std::endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	Police(const Police& ref)
		:handcuffs(ref.handcuffs)
	{
		pistol = new Gun(*(ref.pistol));
	}
	Police& operator=(const Police& ref)
	{
		if (pistol != NULL)
			delete pistol;

		handcuffs = ref.handcuffs;
		pistol = new Gun(*(ref.pistol));
		return *this;
	}
	void PutHandcuff()
	{
		std::cout << "SNAP!" << std::endl;
		handcuffs--;
	}
	void Shut()
	{
		if (pistol == NULL)
			std::cout << "Hut BBANG!" << std::endl;
		else
			pistol->Shut();
	}
	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}
};

int main()
{
	Police pman1(5, 3);
	Police pman2 = pman1;
	pman2.Shut();
	pman2.PutHandcuff();

	Police pman3(0, 3);
	pman3 = pman1;
	pman3.Shut();
	pman3.PutHandcuff();
	return 0;
}