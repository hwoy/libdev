CC=g++
bin=grap.exe
CPPFLAGS=-g -std=c++98 -pedantic -Wall -Werror -Wextra -I../include

.PHONY: all clean

all: $(bin)

$(bin): main.o Cgrap.o CString.o Cexception.o
		$(CC) -o $(bin) main.o Cgrap.o CString.o Cexception.o
clean:
		rm -f *.o $(bin)
		

Cgrap.o: Cgrap.cpp ../include/CString.h ../include/Clinklist.h ../include/Cgrap.h
main.o: main.cpp ../include/CString.h ../include/Clinklist.h ../include/Cgrap.h

CString.o: ../CString/CString.cpp ../include/CString.h
	$(CC)  $(CPPFLAGS)  -c -o CString.o ../CString/CString.cpp
	
Cexception.o: ../Cexception/Cexception.cpp ../include/Cexception.h
	$(CC)  $(CPPFLAGS)  -c -o Cexception.o ../Cexception/Cexception.cpp
