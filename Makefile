
.PHONY: all clean clean-lib install exam

install: all
	find ./ -name *.o | grep -v main.o | grep -v ./lib | xargs -I {} cp -f {} lib 

all:
	make -C Cgrap && \
	make -C Clinklist && \
	make -C Cmsg && \
	make -C Copt && \
	make -C Crandom && \
	make -C CString && \
	make -C Cexception

clean:
	make -C Cgrap clean && \
	make -C Clinklist clean && \
	make -C Cmsg clean && \
	make -C Copt clean && \
	make -C Crandom clean && \
	make -C CString clean && \
	make -C Cexception clean && \
	make -C exam clean && \
	rm -f lib/*.o

clean-lib:
	rm -f lib/*.o
	
exam: install
	make -C exam


