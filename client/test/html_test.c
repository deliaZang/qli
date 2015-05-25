#include <locale.h>
#include "qli.h"

int
main(int argc, char *argv[]){
    if(2 != argc){
        err_quit("Usage: %s <file>", argv[0]);
    }
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();

    FILE *file = Fopen(argv[1], "r");
    struct tab *tab = init_tab(file);
    display_tab(tab);
    distroy_tab(tab);
    Fclose(file);

    endwin();
    return 0;
}