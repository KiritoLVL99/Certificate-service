#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>

using namespace std;

struct GetIniServ
{
	pair<string,int> init;
	GetIniServ()
	{
		init.first="-1";
		init.second=-1;
	}
	pair<string,int> ReadServInfo()
	{
		cout<<"Certify_Server:\n";
		cout<<"enter server_ip and port:\n";
		cin>>init.first>>init.second;
		return init;

	}
};
