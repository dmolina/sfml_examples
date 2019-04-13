CC= g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS = -Wall -g -std=c++11
EXEC = text
DEPS = textboard.h
OBJS = textboard.o main.o
SRCS =  $(OBJS:.o=.cpp)

.PHONY: all clean doc

all: $(EXEC) #doc

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -g $< -o $@

$(EXEC):  $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(EXEC)

clean:
	$(RM) $(EXEC) $(EXEC).o $(OBJS)

doc: $(SRCS)
	doxygen
