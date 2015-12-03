CC=g++
bin=msg.exe
CPPFLAGS=-g -std=c++98 -pedantic -Wall -Werror -Wextra

.PHONY: all clean

all: $(bin)

$(bin): main.o Cmsg.o
		$(CC) -o $(bin) main.o Cmsg.o
clean:
		rm *.o $(bin)
		

Cmsg.o: Cmsg.cpp Cmsg.h
main.o: main.cpp Cmsg.h

