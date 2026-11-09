#include "ui.h"

void init_screen(int height, int width) {
    initscr();
    curs_set(0);
    refresh();
    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    // render top left quadrant
    WINDOW *q1 = newwin(rows / 2, cols / 2, 0, 0);
    box(q1, 0, 0);
    mvwprintw(q1, 0, 2, " Urgent & Important ");

    
    // render top right quadrant
    WINDOW *q2 = newwin(rows / 2, cols / 2, 0, cols / 2);
    box(q2, 0, 0);
    mvwprintw(q2, 0, rows / 2, " Not Urgent & Important ");

    // render bottom left quadrant
    WINDOW *q3 = newwin(rows / 2, cols / 2, rows / 2, 0);
    box(q3, 0, 0);
    mvwprintw(q1, 0, 2, " Urgent & Not Important ");

    // render bottom right quadrant
    WINDOW *q4 = newwin(rows / 2, cols / 2, rows / 2, cols / 2);
    box(q4, 0, 0);
    mvwprintw(q1, 0, 2, " Not Urgent & Not Important ");

    // TODO: maybe make horizontal gap match vertical gap size (12px)

    wrefresh(q1);
    wrefresh(q2);
    wrefresh(q3);
    wrefresh(q4);

    getch();

    endwin();
}