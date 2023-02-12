#include<iostream>
#include"ShopService.h"
#include"windows.h"
#include"SQL.h"


using namespace std;

enum Activity
{
	������������� = 1,
	������������,
	��������������,
	�������������,
	����������������������,
	���������������������,
	����� = 0

};
string ActivityString[] = {
	"�����",
	"�������� �����",
	"������� �����",
	"�������� ������",
	"������� ������",
	"������� ������� ��������",
	"������� ������� �������"
	};
string to_string(Activity e) {
	return ActivityString[(int)e];
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ShopService myJob("Dream");
	myJob.create_employers(ShopService::configPath["Employers"], "Dream");
	myJob.saveEmployers();
	int count = 0;
	printf("�������� ��������:\n");
	for (auto item : ActivityString)
	{
		printf("%d. %s\n", count, item.data());
		count++;
	}

	SQL sql;
	return 0;
}