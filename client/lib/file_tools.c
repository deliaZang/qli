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
    long old = ftell(file);
    fseek(file, pos, SEEK_SET);
    ch = fgetc(file);
    fseek(file, old, SEEK_SET);
    return ch;
}

long
file_bytes(FILE *file){
    long res, pos = ftell(file);
    fseek(file, 0, SEEK_END);
    res = ftell(file);
    fseek(file, pos, SEEK_SET);
    return res;
}

long
sunday(FILE *file, const char *pat){
    if(NULL == file || NULL == pat){
        return -1;
    }
    long f_len, p_len;
    const long pos = ftell(file);
    f_len = file_bytes(file);
    p_len = strlen(pat);

    int idx;
    long f = pos, p = 0;

    int c;
    while(!feof(file) && p < p_len){
        while((c = fgetc(file)) == pat[p]){
            ++f, ++p;
            if(p >= p_len){
                fseek(file, pos, SEEK_SET);
                return f-p;
            }else if(f >= f_len){
                fseek(file, pos, SEEK_SET);
                return -1;
            }
        }

        if((idx = index_of(pat, file_pos_char(file, f-p+p_len))) < 0){
            f = ftell(file)-p+p_len+1;
        }else{
            f = ftell(file)-p+p_len-idx-1;
        }
        fseek(file, f, SEEK_SET);
        p = 0;
    }
    fseek(file, pos, SEEK_SET);
    return -1;
}

void
file_over(FILE *file, const char *str){
    fseek(file, sunday(file, str)+strlen(str), SEEK_SET);
}

char *
copy_to_eof(FILE *file){
    char *str;
    long i, len = file_bytes(file) - ftell(file);
    str = Calloc(len + 1, sizeof(char));
    for(i = 0; i < len; ++i){
        str[i] = fgetc(file);
    }
    return str;
}

FILE *
Tmpfile(){
    FILE *f = tmpfile();
    if(NULL == f){
        err_sys("tmpfile error");
    }
    return f;
}
