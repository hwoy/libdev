CC=g++
bin=grap.exe
CPPFLAGS=-g -std=c++98 -pedantic -Wall -Werror -Wextra

.PHONY: all clean

all: $(bin)

$(bin): main.o Cgrap.o CString.o
		$(CC) -o $(bin) main.o Cgrap.o CString.o
clean:
		rm -f *.o $(bin)
		

Cgrap.o: Cgrap.cpp ../CString/CString.h ../Clinklist/Clinklist.h Cgrap.h
main.o: main.cpp ../CString/CString.h ../Clinklist/Clinklist.h Cgrap.h

CString.o: ../CString/CString.cpp ../CString/CString.h
	$(CC)  $(CPPFLAGS)  -c -o CString.o ../CString/CString.cpp

