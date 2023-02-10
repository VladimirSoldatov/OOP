#pragma once
#include <string>
using namespace std;

// Этап третий
class Item // Класс деталей
{
	string name;
	float price;
	int quantity;
	int ID;
public:
	Item(string _name, float _price, int _quantity);
	void add_quantity(int _value);
	void delete_quantity(int _value);
	string Name();
	int& Quantity(); 
	int getItemIDs(string path);
	void setItemIDs(string path);
	float& Price();

};

