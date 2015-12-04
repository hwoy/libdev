CC=g++
CPPFLAGS=-g -std=c++98 -pedantic -Wall -Werror -Wextra
bin=str.exe

.PHONY: all clean

all: $(bin)

$(bin):	main.o CString.o function.o
	$(CC) -o $(bin) main.o CString.o function.o
	
clean:
	rm -f *.o $(bin)

CString.o: CString.cpp CString.h

main.o: main.cpp CString.h scvt.h

function.o: function.c function.h

