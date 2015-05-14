#ifndef _QLI_H
#define _QLI_H

#include <stdio.h>
#include <fcntl.h>
#include <netdb.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "html_tags.h"

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
long
length_end_with(FILE *file, char ch);
char *
copy_end_with(FILE *file, int ch);
/**
   file_tools end
 */

/**
   string_tools start
 */
#define MAXSTRING 4096
extern char strbuf[];

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
   string_tools end
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
   error end
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
insert(struct DLlist *cur, void *data);
struct DLlist *
delete(struct DLlist *cur);
void *
getdata(const struct DLlist *cur);
/**
   algorithm end
 */

/**
   display start
 */
typedef void (*tag_func)(struct html *);
struct tag_funcs{
    tag_func before;
    tag_func dothis;
    tag_func after;
};

extern const struct tag_funcs tag_funcs[HTML_TAGS];
/**
   display start
 */

/**
   html start
 */
struct html{
    enum HtmlTag type;
    struct html *parent;
    struct DLlist *child;
    void *data;
};

struct tab{
    struct DLlist *root;
    FILE * file;
};

struct link{
    struct html *item;
};

#define before(tag) (tag_funcs[(tag)->type].before(tag))
#define after(tag) (tag_funcs[(tag)->type].after(tag))
#define dothis(tag) (tag_funcs[(tag)->type].dothis(tag))

extern const char *html_tag[HTML_TAGS];

struct tab*
init_tab(FILE *file);
void
distroy_tab(struct tab *tab);
void
display_tab(const struct tab *tab);
/**
   html end
 */

#endif