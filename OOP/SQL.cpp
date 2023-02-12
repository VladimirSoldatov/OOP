#include "Sql.h"
#include <iostream>
#include <windows.h>
#include <oledb.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
#import "C:\Program Files (x86)\Common Files\System\ado\msado15.dll" no_namespace rename("EOF", "EndOfFile")


SQL::SQL()
{
	CoInitialize(NULL);
	_ConnectionPtr pConn(__uuidof(Connection));
	_RecordsetPtr pRs(__uuidof(Recordset));

	//_bstr_t strCnn("Data Source=(localdb)\ProjectsV12;Initial Catalog=master;Integrated Security=True;Connect Timeout=30;Encrypt=False;TrustServerCertificate=False;");


	pConn->Open(L"provider=SQLOLEDB;initial catalog=Test;data source=np:\\\\.\\pipe\\LOCALDB#2653593C\\tsql\\query;Trusted_Connection=yes;", L"", L"", 0);
	string sqlTest = "IF NOT EXISTS(SELECT * FROM sys.databases WHERE name = 'Test') BEGIN CREATE DATABASE Test END";
	pRs = pConn->Execute(sqlTest.data() , NULL, adCmdText);
	pRs.Release();
	sqlTest = "USE TEST;IF NOT EXISTS(SELECT * FROM TEST) BEGIN CREATE Table TEST(Id INT) END";
	pRs = pConn->Execute(sqlTest.data(), NULL, adCmdText);
	pRs.Release();
	sqlTest = "select * from test";
	pRs = pConn->Execute(sqlTest.data(), NULL, adCmdText);

	while (!pRs->EndOfFile)
	{
		printf((_bstr_t)pRs->GetCollect("Id"));
		printf("\n");
		pRs->MoveNext();
	}

	pRs.Release();
	pConn.Release();
	::CoUninitialize();
}
