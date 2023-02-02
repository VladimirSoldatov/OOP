#include<iostream>
#include"ShopService.h"
using namespace std;

int main()
{
	ShopService myJob("Dream");
	myJob.create_employers("Text.txt", "Dream");

	return 0;
}