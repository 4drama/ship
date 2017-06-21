CC=g++
CFLAGS=-c -Wall -std=c++11 -g
LDFLAGS=
SOURCES=main.cpp item.cpp ship_struct.cpp ship.cpp collector.cpp set_item.cpp item_list.cpp ship_preset.cpp new_ship_attributes.cpp space_object.cpp object_list.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ship

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	rm -rf *.o $(EXECUTABLE)