#include "ShopService.h"
#include<iostream>
#include<fstream>
#include<string>
#include"windows.h"

void ShopService::create_employers(string path_file, string _nameOrganization)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string line;
	char* fName = new char[20];
	char * mName = new char[20];
	char * lName = new char[20];
	int age;
	int position;
	int department;

	fstream file(path_file, std::ios_base::in);
	while (!file.eof())
	{
		getline(file, line);
		sscanf_s(line.data(), "%s %s %s %d %d %d", lName, 10, mName,
			10, fName, 20, &age, &position, &department);
		employers.push_back(Employer(lName, mName, fName, age, position, department));
		
	}
	file.close();
}

ShopService::ShopService(string _nameOrganization)
{
	shop = Shop();
	service = Service();
	nameOrganization = _nameOrganization;
}

void ShopService::visit_client(int type_of_visit, string clientName)
{
	if (type_of_visit)
	{
		service.EnterClient(clientName);
		for (auto man : employers)
		{
			man.sayYourName();
		}
	}
	else
	{
		shop.EnterClient(clientName);
		for (auto man : employers)
		{
			man.sayYourName();
		}

	}
		


}
