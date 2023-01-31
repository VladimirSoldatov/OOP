#pragma once
#include"Shop.h"
#include"Service.h"
#include"Employers.h"

enum typeVisit
{
	toBuy = 0,
	toRepair = 1
};
class ShopService :public Shop, public Service
{
	vector<Employer> employers;
	Shop shop;
	Service service;
public:
	ShopService();
	void visit_client(int type_of_visit, string clientName);
		
};

