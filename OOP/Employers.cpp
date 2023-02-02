#include "Employers.h"
enum Departments
{
	Management,
	Sellers,
	Repairmen


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
	int _age, int _department, int position)
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
