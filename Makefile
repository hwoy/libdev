CC=g++
bin=grap.exe
CPPFLAGS=-g -std=c++98 -pedantic -Wall -Werror -Wextra

.PHONY: all clean

all:
	make -C Cgrap && \
	make -C Clinklist && \
	make -C Cmsg && \
	make -C Copt && \
	make -C Crandom && \
	make -C CString
clean:
	make -C Cgrap clean && \
	make -C Clinklist clean && \
	make -C Cmsg clean && \
	make -C Copt clean && \
	make -C Crandom clean && \
	make -C CString clean
	rm -f include/*.h lib/*.o
install: all
	find ./ -name *.o | grep -v main.o | xargs -I {} cp {} lib && \
	find ./ -name *.h | xargs -I {} cp {} include


