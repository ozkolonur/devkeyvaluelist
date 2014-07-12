CFLAGS := -ggdb
INC := -I.
CC := gcc

ifneq ($(V),)
	CFLAGS += -Wall
endif

all: kvlist

kvlist: kvlist.c
	$(CC) $(CFLAGS) $(INC) -o kvlist kvlist.c 
    
clean:
	rm -f kvlist

