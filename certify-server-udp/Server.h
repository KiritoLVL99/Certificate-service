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

using namespace std;

class Server
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
};
