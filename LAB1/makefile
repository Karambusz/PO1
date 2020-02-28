CC=g++
CFLAGS=-c -Wall
FLAGS=-g -Wall
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
all: exec
exec: $(OBJ)
	$(CC) $(FLAGS) $^ -o exec
%.o:%.cpp %.h
	$(CC) $(CFLAGS) -g $<
%.o:%.cpp 
	$(CC) $(CFLAGS) -g $<
clean:
	rm -rf $(OBJ) exec
run: exec
	./exec
valgrind: exec
	valgrind --tool=memcheck ./exec
.PHONY: all clean run valgrind