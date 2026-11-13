#include "ui.h"

static void init_quadrant(Quadrant *q, const char *title, int h, int w, int y, int x) {
    q->title = title;
    q->box = newwin(h, w, y, x);
    box(q->box, 0, 0);
    q->inner = (derwin(q->box, h - 2, w - 2, 1, 1));
    q->count = 0;
    wrefresh(q->box);
}

void init_screen(void) {

    initscr();
    cbreak;
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    refresh();
    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    init_quadrant(&q[0], "Urgent & Important", rows / 2,        cols / 2,        0,               0);
    init_quadrant(&q[1], "Urgent & Not Important", rows / 2,        cols - cols / 2, 0,        cols / 2);
    init_quadrant(&q[2], "Not Urgent & Important", rows - rows / 2, cols / 2,        rows / 2,        0);
    init_quadrant(&q[3], "Not Urgent & Not Important", rows - rows / 2, cols - cols / 2, rows / 2, cols / 2);

    for (int i = 0; i < 4; i++) {
        draw_title(&q[i], i == active);
    }
}

void handle_key(int ch) { 
    if (ch == '\t') {
        int prev = active;
        active = (active + 1) % 4;
        draw_title(&q[prev], false);
        draw_title(&q[active], true);
    }
    if (ch == KEY_ENTER) {
        // select and go into quadrant
    }
}

void delete_screen(void) {
    for (int i = 0; i < 4; i++) {
        delwin(q[i].inner); 
        delwin(q[i].box);
    }
    endwin();
}