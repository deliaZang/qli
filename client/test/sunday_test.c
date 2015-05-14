#include "qli.h"

int
main(int argc, char *argv[]){
    if(3 != argc){
        err_quit("Usage: %s <file> <string>\n", argv[0]);
    }
    FILE *file = Fopen(argv[1], "r");
    printf("%ld\n", sunday(file, argv[2]));
    Fclose(file);
    return 0;
}