CC=g++
CFLAGS=-c
LDFLAGS=
SOURCES=pinset.cpp frame.cpp
OBJECTS=$(SOURCES:.cpp=.o)


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

frameTest: frame.o pinset.o frameTest.o
	$(CC) $(LDFLAGS) frame.o pinset.o -o $@