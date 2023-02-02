#pragma once
#include "Human.h"

class Employer:Human
{
	
	int position;
	int department;
public:
	Employer(string _last_name, string _middle_name, string _first_name, int _age, int _department,
	int position);
	void setPosition(int _position);
	void setPosition(int _position, int _department);
	void sayYourName(string name) override;
};

