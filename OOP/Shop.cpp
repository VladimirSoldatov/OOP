#include <iostream>
#include "Shop.h"
#include "Items.h"
#include "Entrances.h"
#include <fstream>
#include <string>
#include "ShopService.h"
#include "windows.h"


Shop::Shop()
{
	goods = vector<Item>();
	setup_goods(ShopService::configPath["Goods"]); // ��� �������� ������� ������ Shop ��������� ������ ������� ��� �������
}

void Shop::setup_goods(string name, float price, int quantity, int ID) // ����������� ������� ��� ���������� ����� ������� ������
{
	
	bool flag = false;
	for (auto& good : goods)
	{

		if (good.Name() == name && good.Price() == price)
		{
			good.add_quantity(quantity);
			flag = true;
			break;
		}	
	}
	if (!flag)
		goods.push_back(Item(name, price, quantity, ID));
		
}

void Shop::setup_goods(string file_path)
{
	fstream file (file_path, std::ios_base::in); //��������� ���� � ������ ������
	char* name = new char[50];//������� ������ char ��� �������� ���������� ������
	float price; // ���������� ��� ���������� �� ������������� ������
	int quantity; // ���������� ��� ������������� ������. ������, ��� ������ ����� ���������� ��������
	int ID; // ������������� ������
	string line; // ���������� ��� �������� ��������� ������
	while (!file.eof())  // ���� ��� ������ ����� �� ��� �����
	{
		getline(file, line); // ��������� ������ �� ����� file � ��������� � ���������� line
		if (line == "")
			continue;
		sscanf_s(line.data(),"%d %s %f %d", &ID, name, 20, &price, &quantity); // ������ ����� �� ����� ������
		setup_goods(name, price, quantity, ID);
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
		// ���������� �������� ����� ���������� ������� ����� ����, ��� ���������� ��������� ���� �� �������� ����������
	}
	file.close(); // ��������� ���� ����� ������
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
	//������ ������ � ��������.
	entrances.push_back(tmp);
}

void Shop::saveGoods(string file_path)
{

		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		fstream file(file_path, ios_base::out);
		char* tmp = new char[100];
		for (auto item: goods)
		{

			sprintf_s(tmp, 100, "%d %s %.2f %d\n"
				, item.ID, item.name.data(), item.price, item.quantity);
			file << tmp;
		}
		file.close();

	

}
