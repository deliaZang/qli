#include "qli.h"

char http_head[] = "GET / HTTP/1.0\nHost:127.0.0.1:8080\n\n";

int
main(int argc, char *argv[])
{
    if(2 < argc){
        printf("Usage: %s [addr] [post]\n", argv[0]);
        exit(0);
    }

    int fd, n;
    char recivline[MAXLINE+1];
    struct sockaddr_in addr;
    short port = (NULL == argv[2]) ? 80 : atoi(argv[2]);

    fd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&addr, sizeof(addr));
    Inet_pton(AF_INET, argv[1], &addr.sin_addr);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    Connect(fd, (SA *)&addr, sizeof(addr));

    Write(fd, http_head, strlen(http_head));
    while((n = Read(fd, recivline, MAXLINE))){
        recivline[n] = 0;
        Fputs(recivline, stdout);
    }
    close(fd);
    exit(0);
}