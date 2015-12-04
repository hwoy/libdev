CC=g++
bin=list.exe
CPPFLAGS=-g -std=c++98 -pedantic -Wall -Werror -Wextra

.PHONY: all clean

all: $(bin)

$(bin): main.o
		$(CC) -o $(bin) main.o
clean:
		rm -f *.o $(bin)
		
main.o: main.cpp Clinklist.h

