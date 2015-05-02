#ifndef _QLI_H
#define _QLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/**
   socket_tools start
 */
#define BACKLOG 5
#define MAXLINE 4096
#define SA struct sockaddr

int
tcp_connect(const char *host, const char *serv);
int
Accept(int fd, SA * sa, socklen_t *salenptr);
void
Listen(int sockfd, int backlog);
void
Bind(int sockfd, const SA * addr, socklen_t addrlen);
void
Connect(int sockfd, const SA * addr, socklen_t addrlen);
void
Inet_pton(int af, const char *src, void *dst);
int
Socket(int domain, int type, int protocol);
/**
   socket_tools end
 */


/**
   config_tools start
 */
#define CONF_NAME ".qli.config"

#define N_GET 2
#define KEY_SIZE 20
#define VALUE_SIZE 50

struct {
    char user_name[VALUE_SIZE];
    char user_token[VALUE_SIZE];
}config;

char *
get_user_name();
char *
get_user_token();
void
do_gets(char *key_value);
void
load_config();
/**
   config_tools end
 */

/**
   file_tools start
 */

void
Fputs(const char *s, FILE *stream);
long
Read(int fd, char *buf, size_t nbytes);
void
Write(int fd, char *buf, size_t nbytes);
FILE *
Fopen(const char *path, const char *mode);
int
read_line(FILE * file, char * str, long count);
void
Fclose(FILE *fp);
/**
   file_tools end
 */

/**
   string_tools start
 */

#define MAXSTRING 4096

const char *
strjoin(const char *left, const char *right, const char *format);
int
not_empty(const char * str);
int
not_annotation(const char * str);
char **
split(char *str, int division);
void *
Malloc(size_t size);
void *
Calloc(size_t nmemb, size_t size);
/**
   string_tools start
 */

/**
   error start
 */

void
err_ret(const char *fmt, ...);
void
err_sys(const char *fmt, ...);
void
err_dump(const char *fmt, ...);
void
err_msg(const char *fmt, ...);
void
err_quit(const char *fmt, ...);
/**
   error start
 */

/**
   algorithm start
 */

struct DLlist{
    struct DLlist *prev;
    struct DLlist *next;
    void *data;
};

struct DLlist *
insert(struct DLlist *dll, void *data);
struct DLlist *
delete(struct DLlist *dll);
void *
getdata(const struct DLlist *dll);
/**
   algorithm start
 */
#endif