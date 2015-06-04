#include "qli.h"

// FIXME
static struct URL *
parse_url(const struct URL *parent, const char *url){
    const char *HTTP = "http://";
    int start = 0, host_index, post_index, path_index;
    struct URL *url_t = Calloc(1, sizeof(struct URL));
    url_t->url = url;
    url_t->post = "80";
    url_t->path = "/";
    if(0 == start_with(url, HTTP)){
        start = strlen(HTTP);
        host_index = start;
        post_index = (-1 == index_of_char(url+start, ':')) ? -1 : start+index_of_char(url+start, ':');
        path_index = (-1 == index_of_char(url+start, '/')) ? -1 : start+index_of_char(url+start, '/');
        if(-1 != path_index){
            url_t->path = copy_to(url+path_index, strlen(url+path_index));
            if(-1 != post_index){
                url_t->post = copy_to(url+post_index+1, path_index-post_index-1);
                url_t->host = copy_to(url+host_index, post_index-host_index);
            }else{
                url_t->host = copy_to(url+host_index, path_index-host_index);
            }
        }else{
            if(-1 != post_index){
                url_t->post = copy_to(url+post_index+1, strlen(url+post_index+1));
                url_t->host = copy_to(url+host_index, post_index-host_index);
            }else{
                url_t->host = copy_to(url+host_index, strlen(url+host_index));
            }
        }
    }else{
        if(NULL == parent) return NULL;
        url_t->url = url;
        url_t->host = parent->host;
        url_t->post = parent->post;
        if('/' == url[0]){
            url_t->path = url;
        }else{
            char *s = copy_to(parent->path, last_of_char(parent->path, '/')+1);
            char *path = strjoin(s, url, NULL);
            free(s);
            url_t->path = path;
        }
    }
    return url_t;
}

struct URL *
Parse_url(const struct URL *parent, const char *url){
    struct URL *url_t = parse_url(parent, url);
    if(NULL == url_t){
        err_quit("web_browser error: URL is %s", url);
    }
    return url_t;
}

int
web_browser(const struct URL *parent, const char *url)
{
    int sockfd, n;
    char buffer[MAXLINE];
    struct URL *url_t = Parse_url(parent, url);
    // TODO 解析URL路径
    if(-1 == (sockfd = tcp_connect(url_t->host, url_t->post))){
        goto error;
    }

    sprintf(buffer, "GET %s HTTP/1.0\n\n", url_t->path);
    if(strlen(buffer) != write(sockfd, buffer, strlen(buffer))){
        goto error;
    }

    FILE *temp, *file = fdopen(sockfd, "r");
#ifdef _MY_DEBUG
    while(EOF != read_line(file, buffer, MAXLINE)){
        fputs(buffer, stdout);
    }
#else
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
    tab->url = url_t;
    display_tab(tab);
    distroy_tab(tab);
    fclose(temp);
#endif
    return 0;

error:
    return -1;
}