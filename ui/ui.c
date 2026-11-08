#include "ui.h"

void init_screen(int height, int width) {
    initscr();
    int rows, cols;
    getmaxyx(stdscr, rows, cols);


    // draw x-axis
    mvhline(rows / 2, 0, ACS_HLINE, cols);

    // draw y-axis
    mvvline(0, cols / 2, ACS_VLINE, rows);

    refresh();
    getch();
    endwin();
}