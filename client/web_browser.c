#include "qli.h"

char http_head[] = "GET / HTTP/1.0\nHost:127.0.0.1:8080\n\n";

int
main(int argc, char *argv[])
{
    int sockfd, n;
    char recivline[MAXLINE];
    if(2 == argc){
        sockfd = tcp_connect(argv[1], "80");
    }else if(3 == argc){
        sockfd = tcp_connect(argv[1], argv[2]);
    }else{
        err_quit("Usage: %s [addr] [post]\n", argv[0]);
    }

    Write(sockfd, http_head, strlen(http_head));
    while((n = Read(sockfd, recivline, MAXLINE))){
        recivline[n] = 0;
        Fputs(recivline, stdout);
    }
    close(sockfd);
    exit(0);
}