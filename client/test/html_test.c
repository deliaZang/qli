#include "qli.h"

int
main(int argc, char *argv[]){
    if(2 != argc){
        err_quit("Usage: %s <file>", argv[0]);
    }

    FILE *file = Fopen(argv[1], "r");
    struct tab *tab = init_tab(file);
    display_tab(tab);

    Fclose(file);
    return 0;
}