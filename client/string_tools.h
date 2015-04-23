#ifndef _STRING_TOOLS_H
#define _STRING_TOOLS_H

#include "qli.h"
#define MAXSTRING 4096
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

#endif
