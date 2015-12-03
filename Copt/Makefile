CC=g++
CPPFLAGS=-g -std=c++98 -pedantic -Wall -Werror -Wextra
bin=opt.exe

.PHONY: all clean

all:	$(bin)
clean:
	rm -f *.o $(bin)
$(bin):	main.o CString.o Copt.o
	$(CC) -o $(bin) main.o CString.o Copt.o 


Copt.o: Copt.cpp CString.h Copt.h
CString.o: CString.cpp CString.h
main.o: main.cpp CString.h Copt.h

