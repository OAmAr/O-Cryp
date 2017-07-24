CC     = gcc
CFLAGS = -g
RM     = rm -f

default: all
all: crypt

crypt: crypt.c
	$(CC) $(CFLAGS) -o crypt crypt.c -lcrypt

