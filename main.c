#include "stdio.h"
#include "item/item.h"
#include "ui/ui.h"

int main(int argc, char* argv[]) {
    printf("Hello, World \n");
    
    int height = 100;
    int width = 100;

    init_screen(height, width);
    return 0;
}