CC=g++
CFLAGS=-g -c
LDFLAGS=-g
SOURCES=pinset.cpp frame.cpp player.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TESTS=frameTest playerTest gameTest
TARGET=


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

frameTest: frame.o pinset.o frameTest.o
	$(CC) $(LDFLAGS) frame.o pinset.o frameTest.o -o $@

playerTest: player.o pinset.o playerTest.o
	$(CC) $(LDFLAGS) player.o pinset.o playerTest.o -o $@

gameTest: pinset.o frame.o game.o gameTest.o
	$(CC) $(LDFLAGS) pinset.o frame.o game.o gameTest.o -o $@

clean:
	rm -rf *.o $(TESTS) $(TARGET)