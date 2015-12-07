CC=g++
bin=rnd.exe
CPPFLAGS=-g -std=c++98 -pedantic -Wall -Werror -Wextra -I../include

.PHONY: all clean

all: $(bin)

$(bin): main.o Crandom.o Cexception.o CString.o
		$(CC) -o $(bin) main.o Crandom.o Cexception.o CString.o
clean:
		rm -f *.o $(bin)
		

Crandom.o: Crandom.cpp ../include/Crandom.h

main.o: main.cpp ../include/Crandom.h

Cexception.o: ../Cexception/Cexception.cpp ../include/Cexception.h
	$(CC)  $(CPPFLAGS)  -c -o Cexception.o ../Cexception/Cexception.cpp
	
CString.o: ../CString/CString.cpp ../include/CString.h
	$(CC)  $(CPPFLAGS)  -c -o CString.o ../CString/CString.cpp


