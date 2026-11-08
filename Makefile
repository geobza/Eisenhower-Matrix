CC = gcc
CFLAGS = -Wall -Wextra -g -I. -MMD -MP

SRCS = main.c item/item.c ui/ui.c
OBJS = $(SRCS:.c=.o)

main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS:.o=.d) main

-include $(OBJS:.o=.d)
.PHONY: clean