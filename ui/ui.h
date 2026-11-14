#ifndef UI_H
#define UI_H

#include <ncurses.h>
#include <string.h>
#include <stdbool.h>
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
static Quadrant q[4];
static int active = 0;

void init_screen(void);
static void init_quadrant(Quadrant *q, const char *title, int h, int w, int y, int x);

void draw_screen(WINDOW *win, Quadrant q, const TaskList *tasks, int count, int selected, int scroll); // refresh upon updating

void handle_key(int ch);

void add_item_prompt(Quadrant *q);

void remove_item_prompt(Quadrant *q);


static void draw_title(const Quadrant *q, bool highlighted) {
    if (highlighted) wattron(q->box, A_REVERSE);
    mvwprintw(q->box, 0, 2, " %s ", q->title);
    if (highlighted) wattroff(q->box, A_REVERSE);
    wrefresh(q->box); 
}

#endif