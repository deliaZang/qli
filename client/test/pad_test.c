#include <curses.h>
int main()
{
    initscr();
	cbreak();
    noecho();

    WINDOW *pad;

    pad = newpad(1000, getmaxx(stdscr));
    keypad(pad, TRUE);

    refresh();
    wrefresh(pad);

	int i;
	for(i = 0; i < 10; ++i){
		wprintw(pad, "%d\n", i);
	}

    i = 0;
    do{
        clear();
        refresh();
        prefresh(pad, i++, 0, 0, 0, 10, 10);
    }while(wgetch(pad));
    getch();
    endwin();
	return 0;
}
