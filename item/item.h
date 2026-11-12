#ifndef ITEM_H
#define ITEM_H

#define MAX_TASKS 100
#define MAX_TEXT 128

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

void add_task(TaskList *list, const char *text, Quadrant quad);
void remove_task(TaskList *list, int index);
void search_task(TaskList *list, const char *text); // match text by character like nvim // ctrl+f search
void free_list(TaskList *list);

#endif