#include <iostream>
#include "../CString/CString.h"
#include "Copt.h"


Copt::Copt(int argc,const char **argv,const char **param,unsigned int bsize,unsigned int start)
{
	set(argc,argv,param,bsize,start);
}

void Copt::set(int argc,const char **argv,const char **param,unsigned int bsize,unsigned int start)
{
	if(buff.get())
	buff.destroy();
	
	buff.balloc(bsize);
	init(argc,argv,param,start);	
}

void Copt::destroy()
{
	if(buff.get())
	buff.destroy();

	this->argc=0;
	this->argv=NULL;
	this->param=NULL;
	this->index=0;
	this->start=0;
	
}

	int Copt::getindex () const
	{
		return index;
	}
	
	void Copt::setindex (unsigned int index)
	{
		this->index=index;
	}
	
	int Copt::getstart () const
	{
		return start;
	}
	
	void Copt::setstart (unsigned int start)
	{
		this->start=start;
	}
	
	int Copt::getargc() const
	{
		return argc;
	}
	
	void Copt::setargc(int argc)
	{
		this->argc=argc;
	}
	
Cmem<char>& Copt::getbuff()
{
	return buff;
}

	const char **Copt::getargv() const
	{
		return argv;
	}
	
	void Copt::setargv(const char **argv)
	{
		this->argv=argv;
	}
	
	
	const char **Copt::getparam() const
	{
		return param;
	}
	void Copt::setparam(const char **param)
	{
		this->param=param;
	}
	unsigned int Copt::getparamcount() const
	{
		unsigned int i;
		
		for(i=0;param[i];i++);
		return i;
	}
	
void Copt::init(int argc,const char **argv,const char **param,unsigned int start)
{
	this->argc=argc;
	this->argv=argv;
	this->param=param;
	this->index=start;
	this->start=start;
}

void Copt::init(unsigned int start)
{
	this->index=start;
	this->start=start;	
}

int Copt::action ()
{
  unsigned int i, j, k, l;

  buff.get()[0] = 0;


  for (j = index; j < static_cast<unsigned int>(argc); j++)
    {

      for (i = 0; param[i]; i++)
	{

	  if (!(CString::strncmp (argv[j], param[i], CString::strlen (param[i]))))
	    {
	      for (k = 0, l = CString::strlen (param[i]);argv[j][l]; k++, l++)
		{
			if((k+1) >= buff.getsize())  return oom;
				
		  buff.get()[k] = argv[j][l];
		}
	      buff.get()[k] = 0;
	      index= j + 1;
	      return i;
	    }
	}

      for (k = 0, l = 0; argv[j][l]; k++, l++)
	{
		if((k+1) >= buff.getsize())  return oom;
	  buff.get()[k] = argv[j][l];
	}
      buff.get()[k] = 0;
      index= j + 1;
      return other;



    }
  return end;
}


