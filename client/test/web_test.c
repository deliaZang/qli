#include "qli.h"

int main(int argc, char *argv[])
{
    if(2 != argc){
        err_quit("Usage: %s <URL>\n", argv[0]);
    }
    struct URL *parent = NULL, *url = NULL;
    parent = Calloc(1, sizeof(struct URL));
    parent->host = "localhost";
    parent->post = "8080";
    parent->path = "/article/list.html";
    url = Parse_url(parent, argv[1]);
    printf("%s:\nhost: %s, post: %s, path: %s\n", url->url, url->host, url->post, url->path);
    return 0;
}