#ifndef _SOCKET_TOOLS_H
#define _SOCKET_TOOLS_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BACKLOG 5
#define MAXLINE 4096
#define SA struct sockaddr
#define bzero(blk, size) memset(blk, 0, size)

int
Socket(int domain, int type, int protocol){
    int fd;
    if(0 > (fd = socket(domain, type, protocol))){
        perror("socket error\n");
        exit(1);
    }
    return fd;
}

void
Inet_pton(int af, const char *src, void *dst){
    if(0 > inet_pton(af, src, dst)){
        perror("inet_pton error\n");
        exit(1);
    }
}

void
Fputs(const char *s, FILE *stream){
    if(EOF == fputs(s, stream)){
        perror("fputs error\n");
        exit(1);
    }
}

void
Connect(int sockfd, const SA * addr, socklen_t addrlen){
    if(0 > connect(sockfd, addr, addrlen)){
        perror("connect error\n");
        exit(1);
    }
}

void
Bind(int sockfd, const SA * addr, socklen_t addrlen){
    if(0 > bind(sockfd, addr, addrlen)){
        perror("bind error\n");
        exit(1);
    }
}

void
Listen(int sockfd, int backlog){
    if(0 > listen(sockfd, backlog)){
        perror("listen error\n");
        exit(0);
    }
}

int
Accept(int fd, SA * sa, socklen_t *salenptr){
    int acc_fd;
    if(0 > (acc_fd = accept(fd, sa, salenptr))){
        perror("accept error\n");
        exit(0);
    }
    return acc_fd;
}

long
Read(int fd, char *buf, size_t nbytes){
    long n;
    if(-1 == (n = read(fd, buf, nbytes))){
        perror("read error\n");
        exit(0);
    }
    return n;
}

void
Write(int fd, char *buf, size_t nbytes){
    if(nbytes != write(fd, buf, nbytes)){
        perror("write error\n");
    }
}

#endif