#ifndef _CEXCEPTION_H
#define _CEXCEPTION_H

class Cexception
{
	protected:
	const char* file;
	const char* classname;
	const char* method;
	const char* msg;
	char* total;
	
	int ret;
public:
Cexception(const char* file,const char* classname,const char* method,const char* msg,int ret=RET);
~Cexception();

const char *what();

void setfile(const char* file);
void setclassname(const char* classname);
void setmethod(const char* method);
void setmsg(const char* msg);

const char *getfile() const;
const char *getclassname() const;
const char *getmethod() const;
const char *getmsg() const;

int getret() const;

static const int RET=1;
};

#endif

