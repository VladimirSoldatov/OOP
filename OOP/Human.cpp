#include "Human.h"
#include<iostream>

Human::Human() :first_name{}, last_name{}, middle_name{}, age{}// базовый класс человек
{
}

Human::Human(string _last_name, string _first_name, string _middle_name, int _age): // онсутрутор человека
	last_name{ _last_name }, middle_name{ _middle_name }, first_name{_first_name},
	age{_age}
{
}

void Human::sayYourName(string something)
{
	std::cout << "My name is " << last_name << " " << first_name<<"\n";
	std::cout << something;
}

void Human::sayYourName()
{
	std::cout << "My name is " << last_name << " " << first_name << "\n";
}
