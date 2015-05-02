#include "qli.h"

struct {
    char key[KEY_SIZE];
    char *(*func)();
}Gets[N_GET] = {
    {"user name", get_user_name},
    {"user token", get_user_token}
};

char *
get_user_name(){
    return config.user_name;
}

char *
get_user_token(){
    return config.user_token;
}

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
