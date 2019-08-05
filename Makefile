CC      = gcc
CFLAGS  = -g
RM      = rm -f


default: all

all: 001

001: 001.c
	mkdir -p out
	$(CC) $(CFLAGS) -o out/001 001.c

clean veryclean:
	$(RM) Hello