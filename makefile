CC=gcc
CFLAGS=-I.

exe: arbre.h arbre.c noeud.h noeud.c interval.h interval.c main.c
	$(CC) -o exe main.c arbre.c noeud.c interval.c -I.
