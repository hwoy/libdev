#include <iostream>

#include <Cexception.h>

#include <CString.h>

#include <Clinklist.h>

#include <Cgrap.h>




Ccontainer<CString> * Cgrap::addstring(Ccontainer<CString> *dir,const char *str,unsigned int i,unsigned int j)
{
	dir->getobj().balloc(i-j+1);
	dir->getobj().memcpy(&str[j],i-j);
	dir->getobj().get()[i-j]=0;
			
	return add(dir);	
}

void Cgrap::action(const char *str,const char *grap)
{
	unsigned int i,j;
	
	if(!str || !grap)
		throw(Cexception(__FILE__,"Cgrap",__PRETTY_FUNCTION__,"NULL pointers"));
	
	for(j=0,i=0;str[i];)
	{
		if( !CString::strncmp(&str[i],grap,CString::strlen(grap)) )
		{
			addstring(new Ccontainer<CString>,str,i,j);
			
			i+=CString::strlen(grap);
			j=i;
		}
		
		else { i++; }
		
	}
	
	if(i>j)
	{	
		addstring(new Ccontainer<CString>,str,i,j);
	}
}

unsigned int Cgrap::skipgrap(const char *str,char grap,unsigned int i)
{
	unsigned int j;
	for(j=i;str[j]==grap;j++);
	
	return j;
}

void Cgrap::action2(const char *str,char grap)
{
	unsigned int i,j;
	
	if(!str || !grap)
		throw(Cexception(__FILE__,"Cgrap",__PRETTY_FUNCTION__,"NULL pointers"));
	
	for(j=0,i=0;str[i];)
	{
		if( str[i]==grap )
		{
			addstring(new Ccontainer<CString>,str,i,j);
			
			i=skipgrap(str,grap,i);
			j=i;
		}
		
		else { i++; }
		
	}
	
}

