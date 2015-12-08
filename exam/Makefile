CC=g++
CPPFLAGS=-g -std=c++98 -pedantic -Wall -Werror -Wextra -I../include

bin=prime.exe

.PHONY: all clean

all:	$(bin)

clean:
	rm -f *.o $(bin)
	
$(bin):	prime.o
	$(CC) -o $(bin) prime.o ../lib/CString.o ../lib/Copt.o  ../lib/Cexception.o ../lib/Cmsg.o

prime.o: prime.cpp
