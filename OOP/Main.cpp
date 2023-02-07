#include<iostream>
#include"ShopService.h"
using namespace std;

int main()
{
	ShopService myJob("Dream");
	myJob.create_employers("Employers.txt", "Dream");
	myJob.getlastIDEmployers("LastID.txt");
	myJob.addNewEmployer("Гришин",  "Фёдор", "Михайлович", 16, 0, 6);
	myJob.visit_client(1, "Ivan");

	return 0;
}