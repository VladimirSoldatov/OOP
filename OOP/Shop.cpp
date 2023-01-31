#include<iostream>
#include "Shop.h"
#include "Items.h"
#include"Entrances.h";


Shop::Shop()
{
	goods = vector<Item>();
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
