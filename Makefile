CC=g++
CFLAGS=-c
LDFLAGS=
SOURCES=pinset.cpp
OBJECTS=$(SOURCES:.cpp=.o)


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

