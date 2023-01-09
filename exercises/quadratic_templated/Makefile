CC = g++
INCDIR = include
CFLAGS = -I$(INCDIR)

main.x: main.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf *.o *.x
