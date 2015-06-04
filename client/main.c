#include "qli.h"

int
main(int argc, char *argv[])
{
    if(2 != argc){
        err_quit("Usage: %s <URL>\n", argv[0]);
    }
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();

    web_browser(NULL, argv[1]);

    endwin();
    exit(0);
}