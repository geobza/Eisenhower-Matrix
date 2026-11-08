#ifndef ITEM_H
#define ITEM_H

#define MAX_TASKS 100
#define MAX_TEXT 128

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/* 
 *
 * ADD DYNAMIC ARRAY SPACING IN THE FUTURE
 * 
*/
typedef enum {
    Q_URGENT_AND_IMPORTANT,
    Q_NOT_URGENT_AND_IMPORTANT,
    Q_URGENT_AND_NOT_IMPORTANT,
    Q_NOT_URGENT_AND_NOT_IMPORTANT,
    Q_COUNT
} Quadrant;

typedef struct {
    char *text[MAX_TEXT];
    Quadrant quad;
    bool completed;
} Task;

typedef struct {
   Task *tasks[MAX_TASKS];
   int count;
} TaskList;

void add_task();
void remove_task();
void search_task();

#endif