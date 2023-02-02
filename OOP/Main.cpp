#include<iostream>
#include"ShopService.h"
using namespace std;

int main()
{
	ShopService myJob("Dream");
	myJob.create_employers("Text.txt", "Dream");
	myJob.visit_client(1, "Ivan");

	return 0;
}