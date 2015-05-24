#include "qli.h"

char http_head[] = "GET /article/list.html HTTP/1.0\nHost:127.0.0.1:8080\n\n";

int
main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

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

#ifdef _MY_DEBUG
    while(0 != (n = Read(sockfd, recivline, MAXLINE))){
        Write(STDOUT_FILENO, recivline, n);
    }
#else
    FILE *temp, *file = fdopen(sockfd, "r");
    while(EOF != read_line(file, recivline, MAXLINE)){
        if(0 == strcmp("\r", recivline)){
            break;
        }
    }
    temp = fopen("abc.txt", "w+");
    while(0 != (n = Read(sockfd, recivline, MAXLINE))){
        Write(fileno(temp), recivline, n);
    }
    close(sockfd);

    struct tab *tab = init_tab(temp);
    display_tab(tab);
    distroy_tab(tab);
    Fclose(temp);
#endif
    exit(0);
}