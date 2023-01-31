#include "Items.h"
#include<iostream>

Item::Item(string _name, float _price, int _quantity) :name{_name}
, price{ _price }, quantity{ _quantity }
{
}

void Item::add_quantity(int _value)
{
	quantity += _value;
}

void Item::delete_quantity(int _value)
{
	if (quantity >= _value)
		quantity -= _value;
	else
		std::cout << "Error\n";
}

string Item::Name()
{
	return name;
}

int& Item::Quantity()
{
	return quantity;
}

float& Item::Price()
{
	return price;
}
