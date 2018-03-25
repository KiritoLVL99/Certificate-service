#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <time.h>
#include <map>
#include <set>
#include <vector>
#include <utility>

#include "Server.h"
#include "GetIniServ.h"

using namespace std;


int main()
{

	GetIniServ serv_info;

	pair<string,int> init = serv_info.ReadServInfo();

	Server serv(init.first,init.second);

	serv.RunnServer();
	cout<<"Server run\n";

    return 0;

}
