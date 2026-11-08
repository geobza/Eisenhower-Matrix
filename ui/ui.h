#ifndef UI_H
#define UI_H

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "item.h"

#define QUADRANT_WIDTH 100
#define QUADRANT_HEIGHT 100

enum commands { ENTER, A, R, M, ESC };
enum direction { UP, DOWN, RIGHT, LEFT }; // be able to move directions?
// text based and gui based modifications
// maybe make parameters a item class

void init_screen(int *height, int *width);
void draw_screen();

#endif