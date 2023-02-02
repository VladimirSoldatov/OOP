#pragma once
#include"Items.h"
#include <string>
#include<vector>
#include"Entrances.h"
using namespace std;
class Shop
{
	vector<Item>goods;
	vector<Entrance> entrances;
public:
	Shop();
	void setup_goods(string name, float price, int quantity);
	void setup_goods(string file_path);
	void setup_goods(Item item);
	void get_item(int quantity, string item_name);
	void get_summary();
	void EnterClient(string clientName);
	

};

