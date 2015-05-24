#include "qli.h"

int
main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();

    int sockfd, n;
    char buffer[MAXLINE];
    if(4 == argc){
        sockfd = tcp_connect(argv[1], argv[2]);
    }else{
        err_quit("Usage: %s [addr] [post] [path]\n", argv[0]);
    }

    sprintf(buffer, "GET %s HTTP/1.0\n\n", argv[3]);
    Write(sockfd, buffer, strlen(buffer));

#ifdef _MY_DEBUG
    while(0 != (n = Read(sockfd, buffer, MAXLINE))){
        Write(STDOUT_FILENO, buffer, n);
    }
#else
    FILE *temp, *file = fdopen(sockfd, "r");
    while(EOF != read_line(file, buffer, MAXLINE)){
        if(0 == strcmp("\r", buffer)){
            break;
        }
    }
    temp = tmpfile();
    while(0 != (n = Read(sockfd, buffer, MAXLINE))){
        Write(fileno(temp), buffer, n);
    }
    close(sockfd);

    struct tab *tab = init_tab(temp);
    display_tab(tab);
    distroy_tab(tab);
    Fclose(temp);
#endif
    endwin();
    exit(0);
}