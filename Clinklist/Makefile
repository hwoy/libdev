CC=g++
bin=list.exe
CPPFLAGS=-g -std=c++98 -pedantic -Wall -Werror -Wextra -I../include

.PHONY: all clean

all: $(bin)

$(bin): main.o Cexception.o CString.o
		$(CC) -o $(bin) main.o Cexception.o CString.o
clean:
		rm -f *.o $(bin)
		
main.o: main.cpp ../include/Clinklist.h

Cexception.o: ../Cexception/Cexception.cpp ../include/Cexception.h
	$(CC)  $(CPPFLAGS)  -c -o Cexception.o ../Cexception/Cexception.cpp
	
CString.o: ../CString/CString.cpp ../include/CString.h
	$(CC)  $(CPPFLAGS)  -c -o CString.o ../CString/CString.cpp

