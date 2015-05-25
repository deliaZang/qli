#include "qli.h"

int
web_browser(const char *path)
{
    int sockfd, n;
    char buffer[MAXLINE];
    // TODO 解析URL路径
    if(-1 == (sockfd = tcp_connect("localhost", "8080"))){
        goto error;
    }

    sprintf(buffer, "GET %s HTTP/1.0\n\n", path);
    if(strlen(buffer) != write(sockfd, buffer, strlen(buffer))){
        goto error;
    }

    FILE *temp, *file = fdopen(sockfd, "r");
    while(EOF != read_line(file, buffer, MAXLINE)){
        if(0 == strcmp("\r", buffer)){
            break;
        }
    }
    temp = tmpfile();
    while(n = read(sockfd, buffer, MAXLINE)){
        if(n < 0){
            goto error;
        }
        if(n != write(fileno(temp), buffer, n)){
            goto error;
        }
    }
    close(sockfd);

    struct tab *tab = init_tab(temp);
    display_tab(tab);
    distroy_tab(tab);
    fclose(temp);
    return 0;

error:
    return -1;
}