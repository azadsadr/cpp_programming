CC = g++
INCDIR = include
CFLAGS = -I$(INCDIR)

main.x: main.o complex.o quad.o coeffs.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

complex.o: src/complex.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

quad.o: src/quad.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

coeffs.o: src/coeffs.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf *.o *.x
