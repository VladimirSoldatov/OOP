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

void Employer::set_ID()
{
	ID = IDs;
}

void Employer::GenIDs()
{
	IDs++;
}

int Employer::IDs = 0;
void Employer::SetEmployerIDs(int ID)
{
	IDs = ID;
}
Employer::Employer(int _ID, string _last_name,  string _first_name, string _middle_name,
	int _age, int _department, int _position, bool _status) :ID{_ID},
	Human(_last_name, _first_name, _middle_name, _age), department{_department},
	position{ _position }, status{_status}
{
	if (_ID == 0)
	{
		GenIDs();
		set_ID();
		ID = IDs;
	}
	else
	{
		SetEmployerIDs(ID);
	}
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
	std::cout << "Добрый день! ";
	Human::sayYourName(orgName);
	std::cout << "Рад видеть Вас в \""<<orgName<<"\"\n";
}


