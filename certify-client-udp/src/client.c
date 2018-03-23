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
};

char message[] = "qwert";
char buf[2048];

int main()
{

	struct client cl;

    cl.sock = socket(AF_INET, SOCK_STREAM, 0);
    if(cl.sock < 0)
    {
        perror("socket");
        exit(1);
    }

    cl.addr.sin_family = AF_INET;
    cl.addr.sin_port = htons(3425); // или любой другой порт...


    char my_addr[] = "127.0.0.5";

    inet_aton(my_addr,&cl.addr.sin_addr);



    if(connect(cl.sock, (struct sockaddr *)&cl.addr, sizeof(cl.addr)) < 0)
    {
        perror("connect");
        exit(2);
    }

    send(cl.sock, message, 2048, 0);
    recv(cl.sock, buf, 2048, 0);

    printf(buf);
    printf("\n");

    close(cl.sock);

    return 0;
}
