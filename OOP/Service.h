#pragma once
#include<vector>
#include"Items.h"
#include"Works.h"
#include"Entrances.h"

class Service
{
	vector<Entrance> entrances;
	vector<Item> repairItems;
	vector<Work> ourWorks;
public:
	Service();
	void EnterClient(string clientName);

};

