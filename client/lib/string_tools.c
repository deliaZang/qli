#include "qli.h"

// FIXME
char strbuf[MAXSTRING+1];

const char *
strjoin(const char *left, const char *right, const char *format){
    memset(strbuf, 0, MAXSTRING+1);
    if(NULL == format){
        snprintf(strbuf, MAXSTRING, "%s%s", left, right);
    }else{
        snprintf(strbuf, MAXSTRING, format, left, right);
    }
    return strbuf;
}

int
not_empty(const char * str){
    if(NULL == str) return -1;
    if(0 == str[0]) return 0;
    return 1;
}

int
not_annotation(const char * str){
    if(NULL == str) return -1;
    if('#' == str[0]) return 0;
    return 1;
}

// FIXME
char **
split(char *str, int division){
    if(NULL == str){
        return NULL;
    }
    int i, len = strlen(str);
    char **ptrs = (char **)calloc(2, sizeof(char *));
    ptrs[0] = str;
    for(i = 0; i < len; ++i){
        if(division == str[i]){
            str[i] = 0;
            ptrs[1] = str+i+1;
            return ptrs;
        }
    }
    return ptrs;
}

void *
Malloc(size_t size){
    void *ptr;
    if(NULL == (ptr = malloc(size))){
        err_sys("malloc error");
    }
    return ptr;
}

void *
Calloc(size_t nmemb, size_t size){
    void *ptr;
    if(NULL == (ptr = calloc(nmemb, size))){
        err_sys("calloc error");
    }
    return ptr;
}

int
start_with(const char *src, const char *start){
    if(NULL == src || NULL == start) return -1;
    int i, len = strlen(start);
    for(i = 0; i < len; ++i){
        if(src[i] != start[i]){
            return 1;
        }
    }
    return 0;
}

int
index_of_char(const char *str, int ch){
    int i, len = strlen(str);
    for(i = 0; i < len; ++i){
        if(ch == str[i]){
            return i;
        }
    }
    return -1;
}

int
last_of_char(const char *str, int ch){
    int i, len = strlen(str);
    for(i = len-1; i >= 0; --i){
        if(ch == str[i]){
            return i;
        }
    }
    return -1;
}

char *
copy_to(const char *src, int index){
    if(NULL == src || 0 >= index) return NULL;
    char *s = Calloc(index+1, sizeof(char));
    snprintf(s, index+1, "%s", src);
    return s;
}