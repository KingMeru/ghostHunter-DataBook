CFLAGS = -Wall -std=c99
CC = gcc
OBJ = main.o ghost.o room.o building.o

a4: main.o ghost.o room.o building.o
	$(CC) $(CFLAGS) -o a4 main.o ghost.o room.o building.o

main.o: main.c defs.h
	$(CC) $(CFLAGS) -c main.c

ghost.o: ghost.c defs.h
	$(CC) $(CFLAGS) -c ghost.c

room.o: room.c defs.h
	$(CC) $(CFLAGS) -c room.c

building.o: building.c defs.h
	$(CC) $(CFLAGS) -c building.c




clean:
	rm -f $(OBJ) a4
