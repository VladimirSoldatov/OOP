#include "Service.h"

Service::Service()
{
	ourWorks = vector<Work>();
	repairItems = vector<Item>();
}

void Service::EnterClient(string clientName)
{
	Entrance tmp(clientName);
	//������ ������ � ��������.
	entrances.push_back(tmp);
}
