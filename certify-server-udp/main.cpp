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

#include "Server.h"

using namespace std;

string GetSerteficate(string identificate);
pair<string,int> ReadServInfo();

int main()
{
	pair<string,int> init=ReadServInfo();

	Server serv(init.first,init.second);
	cout<<"Server run\n";

    char buf[2048];

    serv.listener = socket(AF_INET, SOCK_STREAM, 0);
    if(serv.listener < 0)
    {
        perror("socket"); //diagnostick send
        exit(1);
    }

    if(bind(serv.listener, (struct sockaddr *)&serv.addr, sizeof(serv.addr)) < 0)
    {
        perror("bind");
        exit(2);
    }

    listen(serv.listener, 1);

    while(1)
    {
        serv.sock = accept(serv.listener, NULL, NULL);
        if(serv.sock < 0)
        {
            perror("accept");
            exit(3);
        }

        while(1)
        {
            serv.bytes_read = recv(serv.sock, buf, 2048, 0);

            if(serv.bytes_read <= 0)
            {
            	break;
            }
            cout<<buf<<endl;

            string kkt = buf;
            string buf1 = GetSerteficate(kkt);

            char buf2[2048];
            strcpy(buf2,buf1.c_str());

            send(serv.sock, buf2, serv.bytes_read, 0);

        }

        close(serv.sock);
    }

    return 0;
}

string GetSerteficate(string identificate)
{
	string id = identificate+".txt";
	char id1[70];
	strcpy(id1,id.c_str());

	freopen(id1,"r",stdin);
	string result="";
	string res;

	while(cin>>res)
	{
		result+=res;
	}
	cin>>result;
	return result;
}
pair<string,int> ReadServInfo()
{
	cout<<"Certify_Server:\n";
	cout<<"enter server_ip and port:\n";
	pair<string,int> init;
	cin>>init.first>>init.second;
	return init;

}
