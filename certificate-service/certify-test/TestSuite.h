#include "cxxtest/TestSuite.h"

#include "../certify-server-udp/Server.h"
#include "../certify-server-udp/GetIniServ.h"
//#include "../certify-server-udp/GetIdUser.h"

#include <fstream>
#include <iostream>
#include <string>
#include <utility>

using namespace std;


class MyTestSuite : public CxxTest::TestSuite {
public:

	void testGetServerInitialization()
	{
		GetIniServ info_serv;

		freopen("input.txt","w",stdout);//w

		cout<<"testread"<<" "<<11<<endl;

		pair<string,int> info_read_fun = info_serv.ReadServInfo();

		freopen("input.txt","r",stdin);freopen("output","w",stdout);

		TS_ASSERT_EQUALS("testread",info_read_fun.first);
		TS_ASSERT_EQUALS(11,info_read_fun.second);

	}
	void testGetIDUser()
	{
		GetIdUser info_user;

		string idi = "input";
		freopen("input.txt","w",stdin);
		cout<<idi<<endl;

		string result = info_user.GetSerteficate(idi);

		TS_ASSERT_EQUALS("input",result);
	}
};
