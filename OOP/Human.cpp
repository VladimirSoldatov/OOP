#include "Human.h"
#include<iostream>

Human::Human()
{
}

Human::Human(string _last_name, string _middle_name, string _first_name, int _age):
	last_name{ _last_name }, middle_name{ _middle_name }, first_name{_first_name},
	age{_age}
{
}

void Human::sayYourName()
{
	std::cout << "My name is " << last_name << " " << first_name<<"\n";
}
