#pragma once
#include <string>
using namespace std;
class Work
{
	float price_of_hour;
	string name;
	float worktime;
public:
	Work(string name, float _price_of_hour, float worktime = 1.0f);

};

