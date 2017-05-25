CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp ship_struct.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ship

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	rm -rf *.o $(EXECUTABLE)