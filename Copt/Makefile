CC=g++
CPPFLAGS=-g -std=c++11 -pedantic -Wall -Werror -Wextra -I../include
bin=opt.exe

.PHONY: all clean

all:	$(bin)
clean:
	rm -f *.o $(bin)
$(bin):	main.o CString.o Copt.o Cexception.o
	$(CC) -o $(bin) main.o CString.o Copt.o  Cexception.o


Copt.o: Copt.cpp ../include/CString.h ../include/Copt.h
main.o: main.cpp ../include/CString.h ../include/Copt.h

CString.o: ../CString/CString.cpp ../include/CString.h
	$(CC)  $(CPPFLAGS)  -c -o CString.o ../CString/CString.cpp
	
Cexception.o: ../Cexception/Cexception.cpp ../include/Cexception.h
	$(CC)  $(CPPFLAGS)  -c -o Cexception.o ../Cexception/Cexception.cpp
