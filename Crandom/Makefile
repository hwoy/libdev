CC=g++
bin=rnd.exe
CPPFLAGS=-g -std=c++98 -pedantic -Wall -Werror -Wextra

.PHONY: all clean

all: $(bin)

$(bin): main.o Crandom.o
		$(CC) -o $(bin) main.o Crandom.o
clean:
		rm *.o $(bin)
		

Crandom.o: Crandom.cpp Crandom.h
main.o: main.cpp Crandom.h

