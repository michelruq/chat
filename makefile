CC = g++
CFLAGS= -c -Wall
SOURCES=main.cpp tcpclient/buffer.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=chatclient

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -rf *.o chatclient
