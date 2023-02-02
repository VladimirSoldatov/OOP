#include "Employers.h"
#include<iostream>
enum Departments
{
	Management,
	Sellers,
	Repairmen,
	Common


};
enum Positions
{
	Director,
	DirectorAssistent,
	Ingineer,
	SeniorIngineer,
	Sellman,
	SeniorSellman,
	Accountant,
	Administrator
};

Employer::Employer(string _last_name, string _middle_name, string _first_name,
	int _age, int _department, int _position):
	Human(_last_name, _middle_name, _first_name, _age), department{_department},
	position{_position}
{
}

void Employer::setPosition(int _position)
{
	position = _position;
}

void Employer::setPosition(int _position, int _department)
{
	position = _position;
	department = _department;
}

void Employer::sayYourName()
{
	std::cout << "Hello! ";
	Employer::sayYourName();
	std::cout << "Glad to see you in ";
}
