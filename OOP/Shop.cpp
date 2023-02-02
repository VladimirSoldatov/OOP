#include<iostream>
#include "Shop.h"
#include "Items.h"
#include"Entrances.h";
#include<fstream>
#include<string>


Shop::Shop()
{
	goods = vector<Item>();
	setup_goods("Goods.txt");
}

void Shop::setup_goods(string name, float price, int quantity)
{
	
	bool flag = false;
	for (auto& good : goods)
	{
		if (good.Name() == name and good.Price() == price)
		{
			good.add_quantity(quantity);
			flag = false;
			break;
		}	
	}
	
	if (!flag)
		goods.push_back(Item(name, price, quantity));
		
}

void Shop::setup_goods(string file_path)
{
	fstream file (file_path, std::ios_base::in);
	char* name = new char[20];
	float price;
	int quantity;
	string line;
	while (!file.eof())
	{
		getline(file, line);
		sscanf_s(line.data(),"%s %f %d", name, 20, &price, &quantity);
		setup_goods(name, price, quantity);
		/*bool flag = false;
		for (auto& good : goods)
		{
			if (good.Name() == name and good.Price() == price)
			{
				good.add_quantity(quantity);
				flag = false;
				break;
			}
		}

		if (!flag)
			goods.push_back(Item(name, price, quantity));*/
	}
}

void Shop::setup_goods(Item item)
{
}

void Shop::get_item(int quantity, string item_name)
{
}

void Shop::get_summary()
{
	for (auto good : goods)
	{
		cout << "Name: " << good.Name() 
			<< ", price: " << good.Price() << " , quantity: " 
			<< good.Quantity()<<"\n";
	}
}

void Shop::EnterClient(string clientName)
{
	Entrance tmp(clientName);
	//Логика работы с клиентом.
	entrances.push_back(tmp);
}
