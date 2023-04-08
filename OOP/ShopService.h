#pragma once
#include"Shop.h"
#include"Service.h"
#include"Employers.h"
#include <map>
using namespace std;
enum typeVisit
{
	toBuy = 0,
	toRepair = 1
};
class ShopService
{
	
	Shop shop;
	Service service;
	string nameOrganization;
	vector<Employer> employers;

public:
	ShopService(string _nameOrganistation);
	static map<string, string> configPath;
	void setup_goods();
	void delete_goods();
	void addWork();
	void deleteWork();
	void create_employers(string path_file);
	void getlastIDEmployers(string path_file);
	void visit_client(int type_of_visit, string clientName);
	string getName() { return nameOrganization; }
	void addNewEmployer(string _lName,
		string _fName, string _mName, int _age
		, int _departament, int _position, bool _status = true);
	void addNewEmployer();
	friend string * getPathConfig(ShopService obj);
	void get_out_employers();
	void saveEmployers();
	void saveEmployersIDs();
	int getEmployersIDs();
	~ShopService();
};

