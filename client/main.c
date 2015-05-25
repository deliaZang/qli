#include "qli.h"

int
main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();

    web_browser(argv[3]);

    endwin();
    exit(0);
}