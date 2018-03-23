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

map<string,string > names;

string GetSerteficate(string identificate)
{
	string result;
	result = "univer.ru.txt";
	return result;
}
map<string,string > CreateBD()
{
	map<string,string > names;
	string s="univer.ru";
	names[s]=(GetSerteficate(s));
	return names;
}

int main()
{
	names = CreateBD();

	Server serv("127.0.0.5",3425);

    char buf[2048];

    serv.listener = socket(AF_INET, SOCK_STREAM, 0);
    if(serv.listener < 0)
    {
        perror("socket");
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

            string buf1=names[kkt];
            freopen("univer.ru.txt","r",stdin);
            cin>>buf1;

            char buf2[2048];
            strcpy(buf2,buf1.c_str());

            send(serv.sock, buf2, serv.bytes_read, 0);

        }

        close(serv.sock);
    }

    return 0;
}
