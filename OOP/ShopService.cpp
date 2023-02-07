#include "ShopService.h"
#include<iostream>
#include<fstream>
#include<string>
#include"windows.h"
#include"Employers.h"

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
	int status;
	int ID;

	fstream file(path_file, std::ios_base::in);
	while (!file.eof())
	{
		getline(file, line);
		sscanf_s(line.data(), "%d %s %s %s %d %d %d %d",&ID, lName, 10, fName,
			10, mName, 20, &age, &position, &department, &status);
		employers.push_back(Employer(ID, lName, fName, mName, age, position, department, (bool)status));
	
	}
	file.close();

}

void ShopService::getlastIDEmployers(string path_file)
{
	fstream file(path_file, ios_base::in);
	string line;
	char name[20];
	int ID;
	while (!file.eof())
	{
		getline(file, line);
		auto tmp = line.find("LastEmployerID");
		if (line.find("LastEmployerID") == 0)
		{
			sscanf_s(line.data(), "%s %d", name, 20, &ID);
			Employer::IDs = ID;
		}
	}
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
			man.sayYourName(nameOrganization);
		}
	}
	else
	{
		shop.EnterClient(clientName);
		for (auto man : employers)
		{
			man.sayYourName(nameOrganization);
		}

	}
		


}

void ShopService::addNewEmployer(string _lName, string _fName, string _mName, int _age, int _departament, int _position, bool _status)
{
	employers.push_back(Employer(0, _lName,
		_fName, _mName, _age, _departament
		, _position, _status));
}

void ShopService::get_out_employers()
{
}

void ShopService::saveEmployers()
{
	fstream file("Employers.txt", ios_base::out);
	for (auto emp : employers)
	{
		//printf("%d %s %s %s %d %d %d %d")
		file << printf("%d %s %s %s %d %d %d %d"
			, emp.ID, emp.)
	}
}

