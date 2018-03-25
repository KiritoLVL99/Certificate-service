#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>

using namespace std;

struct GetIdUser
{
public:
	string id;
	char id1[70];

	string GetSerteficate(string identificate)
	{
		id = identificate+".txt";
		strcpy(id1,id.c_str());

		freopen(id1,"r",stdin);
		string result="";
		string res;

		while(cin>>res)
		{
			result+=res;
		}
		//cin>>result;
		return result;
	}
};
