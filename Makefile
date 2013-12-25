CC=g++
CFLAGS=-g -c -std=gnu++11
LDFLAGS=-g
SOURCES=pinset.cpp frame.cpp player.cpp game.cpp playerGame.cpp scoresheet.cpp bowlSimulator.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TESTS=frameTest playerTest gameTest playerGameTest matchTest
TARGET=bowlSimulator


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

all: bowlSimulator

bowlSimulator: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

playerGameTest: frame.o pinset.o player.o game.o playerGame.o scoresheet.o playerGameTest.o
	$(CC) $(LDFLAGS) frame.o pinset.o player.o game.o playerGame.o scoresheet.o playerGameTest.o -o $@

frameTest: frame.o pinset.o frameTest.o
	$(CC) $(LDFLAGS) frame.o pinset.o frameTest.o -o $@

playerTest: player.o pinset.o playerTest.o
	$(CC) $(LDFLAGS) player.o pinset.o playerTest.o -o $@

gameTest: pinset.o frame.o game.o gameTest.o
	$(CC) $(LDFLAGS) pinset.o frame.o game.o gameTest.o -o $@

clean:
	rm -rf *.o $(TESTS) $(TARGET)