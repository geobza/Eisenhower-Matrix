#include "stdio.h"
#include "item/item.h"
#include "ui/ui.h"
#include <ncurses.h>

int main(int argc, char* argv[]) {

    init_screen();
    int ch;
    while ((ch = getch()) != 'q') { // does not properly exit
        handle_key(ch);
    }
    delete_screen();
    return 0;
}