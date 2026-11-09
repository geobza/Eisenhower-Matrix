#ifndef UI_H
#define UI_H

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUADRANT_WIDTH 100
#define QUADRANT_HEIGHT 100

/*
 * UI PLAN: *
 * - be able to navigate UI through typing commands, and through arrow keys / vim motions
 * - render quadrants as their own windows and combine or as one?
 * 
 * 
*/

enum commands { ENTER, A, R, M, ESC };
enum direction { UP, DOWN, RIGHT, LEFT }; // be able to move directions?
// text based and gui based modifications
// maybe make parameters a item class

void init_screen(int height, int width);
void draw_screen(); // refresh upon updating

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