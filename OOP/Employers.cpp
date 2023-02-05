#include "Employers.h"
#include<iostream>
enum Departments
{
	Management,
	Sellers,
	Repairmen,
	Common


}; // Перечисление названия отделов
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
};// Перечисление должностей

Employer::Employer(string _last_name, string _middle_name, string _first_name,
	int _age, int _department, int _position):
	Human(_last_name, _middle_name, _first_name, _age), department{_department},
	position{_position}
{
} //Конструктор создания сотрудника

void Employer::setPosition(int _position) //Смена должности в рамках одного отдела
{
	position = _position;
}

void Employer::setPosition(int _position, int _department) // Смена должности с переводом в другой отдел
{
	position = _position;
	department = _department;
}

void Employer::sayYourName(string orgName) // Предствиться
{
	std::cout << "Hello! ";
	Human::sayYourName(orgName);
	std::cout << "Glad to see you in \""<<orgName<<"\"\n";
}
