CC=g++
bin=msg.exe
CPPFLAGS=-g -std=c++11 -pedantic -Wall -Werror -Wextra -I../include

.PHONY: all clean

all: $(bin)

$(bin): main.o Cmsg.o
		$(CC) -o $(bin) main.o Cmsg.o
clean:
		rm -f *.o $(bin)
		

Cmsg.o: Cmsg.cpp ../include/Cmsg.h
main.o: main.cpp ../include/Cmsg.h

