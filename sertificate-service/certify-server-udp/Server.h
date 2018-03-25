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
#include <vector>

#include "GetIdUser.h"

using namespace std;

struct Server
{
public:
	int sock,listener;
	string my_addr;
	sockaddr_in addr;
	int bytes_read;
	Server()
	{
		my_addr = "127.0.0.1";
		inet_aton(my_addr.c_str(), &addr.sin_addr);
		addr.sin_family = AF_INET;
		addr.sin_port = htons(3425);
	}
	Server(string adr,int port)
	{
		my_addr = adr;
		inet_aton(my_addr.c_str(), &addr.sin_addr);
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
	}
	void RunnServer()
	{
		char buf[2048];
		listener= socket(AF_INET, SOCK_STREAM, 0);
	    if(listener < 0)
	    {
	        perror("socket"); //diagnostick send
	        exit(1);
	    }

	    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	    {
	        perror("bind");
	        exit(2);
	    }

	    listen(listener, 1);

	    GetIdUser get_id;

	    while(1)
	    {
	        sock = accept(listener, NULL, NULL);
	        if(sock < 0)
	        {
	            perror("accept");
	            exit(3);
	        }

	        while(1)
	        {
	            bytes_read = recv(sock, buf, 2048, 0);

	            if(bytes_read <= 0)
	            {
	            	break;
	            }
	            cout<<buf<<endl;

	            string kkt = buf;
	            string buf1 = get_id.GetSerteficate(kkt);

	            char buf2[2048];
	            strcpy(buf2,buf1.c_str());

	            send(sock, buf2, bytes_read, 0);

	        }

	        close(sock);
	    }
	    return;
	}
};
