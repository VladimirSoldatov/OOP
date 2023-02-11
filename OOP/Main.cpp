#include<iostream>
#include"ShopService.h"
#include"windows.h"
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

	myJob.visit_client(1, "Ivan");
	myJob.setup_goods("������", 23, 1);
	return 0;
}