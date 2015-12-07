#include <iostream>

#include <Cexception.h>
#include <CString.h>




Cexception::Cexception(const char* file,const char* classname,const char* method,const char* msg,int ret)
{
CString Total="";
	
setfile(file);
setclassname(classname);
setmethod(method);
setmsg(msg);

this->ret=ret;

	Total=Total+"["+"FILE:" + this->file + "]," + "["+"class:" + this->classname + "]," + "["+"method:" + this->method + "]," + "["+"msg:" + this->msg + "]" ;
	total=new char[Total.getsize()];
	CString::memcpy(total,Total.get(),Total.getsize());
}

Cexception::~Cexception()
{
	delete[] total;
}

const char *Cexception::what()
{
	return total;
}

void Cexception::setfile(const char* file)
{
	this->file=file;
}
void Cexception::setclassname(const char* classname)
{
	this->classname=classname;
}
void Cexception::setmethod(const char* method)
{
	this->method=method;
}
void Cexception::setmsg(const char* msg)
{
	this->msg=msg;
}


const char *Cexception::getfile() const
{
	return file;
}
const char *Cexception::getclassname() const
{
	return classname;
}
const char *Cexception::getmethod() const
{
	return method;
}
const char *Cexception::getmsg() const
{
	return msg;
}

int Cexception::getret() const
{
	return ret;
}

