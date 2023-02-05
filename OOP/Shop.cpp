#include<iostream>
#include "Shop.h"
#include "Items.h"
#include"Entrances.h"
#include<fstream>
#include<string>


Shop::Shop()
{
	goods = vector<Item>();
	setup_goods("Goods.txt"); // При сздании объекта класса Shop принимаем список товаров для продажи
}

void Shop::setup_goods(string name, float price, int quantity) // примитивная функция для добавления одной позиции товара
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
	fstream file (file_path, std::ios_base::in); //Открываем файл в режиме чтения
	char* name = new char[20];//Создаем массив char для хранения символьных данных
	float price; // Переменная для сохранения не целочисленных данных
	int quantity; // Переменная для целочисленных данных. Исходи, что товары будут продааться поштучно
	string line; // Переменная для хранения считанной строки
	while (!file.eof())  // Цикл для чтения файла до его конца
	{
		getline(file, line); // считываем строку из файла file и заисываем в переменную line
		sscanf_s(line.data(),"%s %f %d", name, 20, &price, &quantity); // Парсим сроку по типам данных
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
		// Используем алгоритм более примитивой функции после того, как распарсили текстовый файл до простоых аргументов
	}
	file.close(); // Закрываем файл после чтения
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
