#include <curses.h>
int main()
{
    initscr();
	cbreak();
    noecho();
    keypad(stdscr, TRUE);

    WINDOW *pad;

    pad = newpad(10,10);
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
