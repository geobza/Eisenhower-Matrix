#ifndef UI_H
#define UI_H

#include <ncurses.h>
#include <string.h>
#include "item/item.h"
#define QUADRANT_WIDTH 100
#define QUADRANT_HEIGHT 100

/*
 * UI PLAN: *
 * - be able to navigate UI through typing commands, and through arrow keys / vim motions
 * - render quadrants as their own windows and combine or as one?
 * 
 * Q = quit
 * TAB, LEFT, RIGHT, UP, DOWN = move between quadrants
 * ENTER = select quadrant 
 * UP / DOWN = move up / down between items in the quadrant
 * ENTER = select item, BACKSPACE = remove item,
 * command to add item in quadrant?
 * 
*/

enum commands { ENTER, A, R, M, ESC };
enum direction { UP, DOWN, RIGHT, LEFT }; // be able to move directions?
// text based and gui based modifications
// maybe make parameters a item class

void init_screen(void);
static void init_quadrant(Quadrant *q, int h, int w, int y, int x);
void draw_screen(WINDOW *win, Quadrant q, const TaskList *tasks, int count, int selected, int scroll); // refresh upon updating

static void draw_title(WINDOW *win, const char *title) {
    int h, w;
    getmaxyx(win, h, w);
    (void)h;                               // only the width is needed
    int x = (w - (int)strlen(title) - 2) / 2;   // -2 for the padding spaces
    if (x < 1) x = 1;
    wattron(win, A_BOLD);
    mvwprintw(win, 0, x, " %.*s ", w - 4, title);   // %.*s truncates to fit
    wattroff(win, A_BOLD);
}

#endif