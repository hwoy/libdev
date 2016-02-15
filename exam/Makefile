CC=g++
CPPFLAGS=-g -std=c++11 -pedantic -Wall -Werror -Wextra -I../include
LIBDIR="../lib"
LDFLAGS+=-L$(LIBDIR)

bin=prime.exe

.PHONY: all clean

all:	$(bin)

clean:
	rm -f *.o $(bin)
	
$(bin):	prime.o
	$(CC) $(LDFLAGS) -o $(bin) prime.o -ldev

prime.o: prime.cpp

