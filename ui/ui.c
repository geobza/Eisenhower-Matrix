#include "ui.h"

static void init_quadrant(Quadrant *q, int h, int w, int y, int x) {
    q->box = newwin(h, w, y, x);
    box(q->box, 0, 0);
    q->inner = (derwin(q->box, h - 2, w - 2, 1, 1));
    q->count = 0;
    wrefresh(q->box);
}

void init_screen(void) {
    initscr();
    curs_set(0);
    refresh();
    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    static Quadrant q[4];
    init_quadrant(&q[0], rows / 2, cols / 2, 0, 0);
    init_quadrant(&q[1], rows / 2, cols - cols / 2, 0, cols / 2);
    init_quadrant(&q[2], rows - rows / 2, cols / 2, rows / 2, 0);
    init_quadrant(&q[3], rows - rows / 2, cols - cols / 2, rows / 2, cols / 2);

    /* draw titles and items, then getch() / main loop, then endwin() */
    draw_title(q[0].box, "Urgent & Important");
    draw_title(q[1].box, "Urgent & Not Important");
    draw_title(q[2].box, "Not Urgent & Important");
    draw_title(q[3].box, "Not Urgent & Not Important");

    for (int i = 0; i < 4; i++) {
        wrefresh(q[i].box);
    }

    getch();
    endwin();
}