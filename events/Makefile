CC= g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS = -Wall -g -std=c++11
EXEC = events
OBJS = 
SRCS =  $(OBJS:.o=.cpp)

.PHONY: all clean doc

all: $(EXEC) #doc

%.o: %.cpp
	$(CC) $(CFLAGS) -c -g $< -o $@

$(EXEC):  $(EXEC).o $(OBJS)
	$(CC) $(CFLAGS) $< $(OBJS) $(LIBS) -o $@

clean:
	$(RM) $(EXEC) $(EXEC).o $(OBJS)

doc: $(SRCS)
	doxygen
