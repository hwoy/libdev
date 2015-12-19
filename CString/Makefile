CC=g++
CPPFLAGS=-g -std=c++11 -pedantic -Wall -Werror -Wextra -I../include
bin=str.exe

.PHONY: all clean

all: $(bin)

$(bin):	main.o CString.o Cexception.o
	$(CC) -o $(bin) main.o CString.o Cexception.o
	
clean:
	rm -f *.o $(bin)

CString.o: CString.cpp ../include/CString.h

main.o: main.cpp ../include/CString.h ../include/_scvt.h

Cexception.o: ../Cexception/Cexception.cpp ../include/Cexception.h
	$(CC)  $(CPPFLAGS)  -c -o Cexception.o ../Cexception/Cexception.cpp


