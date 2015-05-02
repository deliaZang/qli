#include "qli.h"

int
Socket(int domain, int type, int protocol){
    int fd;
    if(0 > (fd = socket(domain, type, protocol))){
        err_sys("socket error");
    }
    return fd;
}

void
Inet_pton(int af, const char *src, void *dst){
    if(0 > inet_pton(af, src, dst)){
        err_sys("inet_pton error");
    }
}

void
Connect(int sockfd, const SA * addr, socklen_t addrlen){
    if(0 > connect(sockfd, addr, addrlen)){
        err_sys("connect error");
    }
}

void
Bind(int sockfd, const SA * addr, socklen_t addrlen){
    if(0 > bind(sockfd, addr, addrlen)){
        err_sys("bind error");
    }
}

void
Listen(int sockfd, int backlog){
    if(0 > listen(sockfd, backlog)){
        err_sys("listen error");
    }
}

int
Accept(int fd, SA * sa, socklen_t *salenptr){
    int acc_fd;
    if(0 > (acc_fd = accept(fd, sa, salenptr))){
        err_sys("accept error");
    }
    return acc_fd;
}

int
tcp_connect(const char *host, const char *serv){
    int sockfd, n;
    struct addrinfo hints, *res, *saveres;
    bzero(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if((n = getaddrinfo(host, serv, &hints, &res)) != 0){
        err_quit("tcp_connect error for %s, %s: %s",
            host, serv, gai_strerror(n));
    }
    saveres = res;
    do{
        sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if(sockfd < 0){
            continue;
        }
        if(connect(sockfd, res->ai_addr, res->ai_addrlen) == 0){
            break;
        }
        close(sockfd);
    }while(NULL != (res = res->ai_next));
    freeaddrinfo(saveres);
    if(NULL == res){
        err_quit("tcp_connect error for %s, %s", host, serv);
    }
    return sockfd;
}