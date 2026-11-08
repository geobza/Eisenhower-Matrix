#ifndef UI_H
#define UI_H

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

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

#endif