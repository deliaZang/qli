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
    long len = 0;
    fpos_t pos;
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
    char *str;
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

static int
index_of(const char *src, char c){
    if(NULL == src){
        return -1;
    }
    int i = 0;
    while(src[i]){
        if(c == src[i]){
            return i;
        }
        ++i;
    }
    return -1;
}

int
file_pos_char(FILE *file, long pos){
    int ch;
    fpos_t old;
    fgetpos(file, &old);
    fsetpos(file, &pos);
    ch = fgetc(file);
    fsetpos(file, &old);
    return ch;
}

long
file_length(FILE *file){
    long pos, res;
    fgetpos(file, &pos);
    fseek(file, 0, SEEK_END);
    fgetpos(file, &res);
    fsetpos(file, &pos);
    return res;
}

long
sunday(FILE *file, const char *pat){
    if(NULL == file || NULL == pat){
        return -1;
    }
    long pos, f_len, p_len;
    fgetpos(file, &pos);
    f_len = file_length(file) - pos;
    p_len = strlen(pat);
    fsetpos(file, &pos);

    int idx;
    long f = 0, p = 0;

    while(!feof(file) && p < p_len){
        while(fgetc(file) == pat[p]){
            ++f, ++p;
            if(p >= p_len){
                fsetpos(file, &pos);
                return f-p;
            }else if(f >= f_len){
                fsetpos(file, pos);
                return -1;
            }
        }

        if((idx = index_of(pat, file_pos_char(file, f-p+p_len))) < 0){
            f = f-p+p_len+1;
        }else{
            f = f-p+p_len-idx;
        }
        fsetpos(file, &f);
        p = 0;
    }
    fsetpos(file, pos);
    return -1;
}