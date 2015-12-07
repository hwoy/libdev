CC=g++
CPPFLAGS=-g -std=c++98 -pedantic -Wall -Werror -Wextra -I../include
bin=excep.exe

.PHONY: all clean

all:	$(bin)
clean:
	rm -f *.o $(bin)
$(bin):	main.o CString.o Cexception.o Crandom.o
	$(CC) -o $(bin) main.o CString.o Cexception.o Crandom.o


Cexception.o: Cexception.cpp ../include/CString.h ../include/Cexception.h
main.o: main.cpp ../include/CString.h ../include/Cexception.h

CString.o: ../CString/CString.cpp ../include/CString.h
	$(CC)  $(CPPFLAGS)  -c -o CString.o ../CString/CString.cpp
	
Crandom.o: ../Crandom/Crandom.cpp ../include/Crandom.h
	$(CC)  $(CPPFLAGS)  -c -o Crandom.o ../Crandom/Crandom.cpp
