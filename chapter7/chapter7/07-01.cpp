#include <iostream>

class Car
{
private:
	int gasolineGauge;
public:
	Car(int gas) : gasolineGauge(gas) {}
	int GetGasGauge()
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;
public:
	HybridCar(int gas, int elec)
		: Car(gas), electricGauge(elec) {}
	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGauge;
public:
	HybridWaterCar(int gas, int elec, int water)
		:HybridCar(gas, elec), waterGauge(water) {}
	void ShowCurrentGauge()
	{
		std::cout << "잔여 가솔린 : " << GetGasGauge() << std::endl;
		std::cout << "잔여 전기량 : " << GetElecGauge() << std::endl;
		std::cout << "잔여 워터량 : " << waterGauge << std::endl;
	}
};

int main()
{
	HybridWaterCar hb(10, 20, 30);
	hb.ShowCurrentGauge();
}