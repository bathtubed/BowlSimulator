CC=g++
CFLAGS=-g -c
LDFLAGS=-g
SOURCES=pinset.cpp frame.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TESTS=frameTest
TARGET=


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

frameTest: frame.o pinset.o frameTest.o
	$(CC) $(LDFLAGS) frame.o pinset.o frameTest.o -o $@

clean:
	rm -rf *.o $(TESTS) $(TARGET)