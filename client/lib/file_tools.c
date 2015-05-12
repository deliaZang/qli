#include "qli.h"

void
Fputs(const char *s, FILE *stream){
    if(EOF == fputs(s, stream)){
        err_sys("fputs error");
    }
}

long
Read(int fd, char *buf, size_t nbytes){
    long n;
    if(-1 == (n = read(fd, buf, nbytes))){
        err_sys("read error");
    }
    return n;
}

void
Write(int fd, char *buf, size_t nbytes){
    if(nbytes != write(fd, buf, nbytes)){
        err_sys("write error");
    }
}

FILE *
Fopen(const char *path, const char *mode){
    FILE * file;
    if(NULL == (file = fopen(path, mode))){
        err_sys("fopen error");
    }
    return file;
}

void
Fclose(FILE *fp){
    if(fclose(fp) != 0){
        err_sys("fclose error");
    }
}

int
read_line(FILE * file, char * str, long count){
    if(NULL == str || NULL == file) return EOF;
    if(NULL == fgets(str, count, file)) return EOF;
    int len = strlen(str);
    if('\n' == str[len-1]){
        str[len-1] = 0;
        return len-1;
    }
    return len;
}

long
length_end_with(FILE *file, char ch){
    long pos, len = 0;
    fgetpos(file, &pos);
    while(!feof(file) && ch != fgetc(file)){
        ++len;
    }
    if(feof(file)){
        len = -1;
    }
    fsetpos(file, &pos);
    return len;
}

char *
copy_end_with(FILE *file, int ch){
    char c, *str;
    long i, len = length_end_with(file, ch);
    if(len < 0){
        return NULL;
    }
    str = Calloc(len + 1, sizeof(char));
    for(i = 0; i < len; ++i){
        str[i] = fgetc(file);
    }
    return str;
}