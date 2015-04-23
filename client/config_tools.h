#ifndef _CONFIG_TOOLS_H
#define _CONFIG_TOOLS_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "qli.h"
#include "file_tools.h"
#include "string_tools.h"

#define CONF_NAME ".qli.config"

#define N_GET 2
#define KEY_SIZE 20
#define VALUE_SIZE 50

struct {
    char user_name[VALUE_SIZE];
    char user_token[VALUE_SIZE];
}config;

char *
get_user_name(){
    return config.user_name;
}

char *
get_user_token(){
    return config.user_token;
}

struct {
    char key[KEY_SIZE];
    char *(*func)();
}Gets[N_GET] = {
    {"user name", get_user_name},
    {"user token", get_user_token}
};

void
do_gets(char *key_value){
    char **ptrs = split(key_value, '=');
    if(not_empty(ptrs[1])){
        int i;
        for(i = 0; i < N_GET; ++i){
            if(0 == strcmp(Gets[i].key, ptrs[0])){
                snprintf(Gets[i].func(), VALUE_SIZE, "%s", ptrs[1]);
		free(ptrs);
                return;
            }
        }
    }
    free(ptrs);
}

void
load_config(){
    char buf[MAXLINE];
    char * home = getenv("HOME");
    FILE * file = Fopen(strjoin(home, CONF_NAME, "%s/%s"), "r");
    while(EOF != read_line(file, buf, MAXLINE)){
        if(not_empty(buf) && not_annotation(buf)){
            do_gets(buf);
        }
    }
    fclose(file);
}

#endif
