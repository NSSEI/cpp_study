#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

class Employee
{
private:
	char name[100];
public:
	Employee(char* myname)
	{
		strcpy(name, myname);
	}
	void ShowYourName() const
	{
		std::cout << "name : " << name << std::endl;
	}
	virtual int GetPay() const { return 0; }
	virtual void ShowSalaryInfo() const {}
};

class PermanentWorker :public Employee
{
private:
	int salary;
public:
	PermanentWorker(char* myname, int mysalary)
		:Employee(myname), salary(mysalary) {}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo()
	{
		ShowYourName();
		std::cout << "salary : " << salary << std::endl;
	}
};

class TemporaryWorker :public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(char* myname, int mypay)
		:Employee(myname), payPerHour(mypay) {}
	void addWorkTime(int time)
	{
		workTime += time;
	}
	int GetPay() const
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo()
	{
		ShowYourName();
		std::cout << "salary : " << GetPay() << std::endl;
	}
};

class SalesWorker :public PermanentWorker
{
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(char* name, int money, double ratio)
		:PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}
	void AddSalesResult(int val)
	{
		salesResult += val;
	}
	int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		std::cout << "salary : " << GetPay() << std::endl;
	}
};

namespace RISK_LEVEL
{
	enum
	{
		RISK_A = 30,
		RISK_B = 20,
		RISK_C = 10
	};
}
class ForeignSalesWorker :public SalesWorker
{
private:
	const int risk;
public:
	ForeignSalesWorker(char* name, int money, double ratio, int level)
		:SalesWorker(name, money, ratio), risk(level) {}
	int GetRisk() const
	{
		return(int)(SalesWorker::GetPay() * (risk / 100.0));
	}
	int GetPay() const
	{
		return SalesWorker::GetPay() + GetRisk();
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		std::cout << "salary : " << SalesWorker::GetPay() << std::endl;
		std::cout << "risk pay: " << GetRisk() << std::endl;
		std::cout << "sum : " << GetPay() << std::endl << std::endl;
	}

};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() :empNum(0) {}
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
		std::cout << "salary sum : " << sum << std::endl << std::endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};


int main()
{
	EmployeeHandler handler;

	ForeignSalesWorker* fseller1 = new ForeignSalesWorker((char*)"Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker((char*)"Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker((char*)"Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	handler.ShowAllSalaryInfo();
	return 0;
}