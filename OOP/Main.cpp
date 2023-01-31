#include<iostream>
#include"Shop.h"
using namespace std;

int main()
{
	Shop shop;
	
	shop.setup_goods("Cup", 2.5, 10);
	shop.get_summary();

	return 0;
}