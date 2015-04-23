#ifndef _QLI_H
#define _QLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "socket_tools.h"
#include "string_tools.h"
#include "config_tools.h"

void *
Malloc(size_t size){
    void *ptr;
    if(NULL == (ptr = malloc(size))){
        perror("malloc error\n");
        exit(0);
    }
    return ptr;
}

void *
Calloc(size_t nmemb, size_t size){
    void *ptr;
    if(NULL == (ptr = calloc(nmemb, size))){
        perror("calloc error\n");
        exit(0);
    }
    return ptr;
}

#endif