#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

struct client
{
	int sock;
	struct sockaddr_in addr;
	//char message[30];
};

struct init
{
	char servIP[30];
	int serv_port;
	char yourID[30];
};

struct init ReadServInfo();

char buf[2048];

int main()
{
	struct init read=ReadServInfo();
	struct client cl;

	//char message[30]=read.yourID;
    cl.sock = socket(AF_INET, SOCK_STREAM, 0);
    if(cl.sock < 0)
    {
        perror("socket");
        exit(1);
    }

    cl.addr.sin_family = AF_INET;
    cl.addr.sin_port = htons(read.serv_port);


//char my_addr[] = read.servIP;

    inet_aton(read.servIP,&cl.addr.sin_addr);

    if(connect(cl.sock, (struct sockaddr *)&cl.addr, sizeof(cl.addr)) < 0)
    {
        perror("connect");
        exit(2);
    }

    send(cl.sock, read.yourID, 2048, 0);
    recv(cl.sock, buf, 2048, 0);

    printf(buf);
    printf("\n");

    close(cl.sock);

    return 0;
}

struct init ReadServInfo()
{
	printf("Certify_Client:\n");
	printf("enter the server ip and the port to which you want to connect:\n");
	struct init info;
	scanf("%s %d",&info.servIP,&info.serv_port);
	printf("enter your ID\n");
	scanf("%s",&info.yourID);
	return info;
}
