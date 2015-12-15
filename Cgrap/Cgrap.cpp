#include <iostream>

#include <Cexception.h>

#include <CString.h>

#include <Clinklist.h>

#include <Cgrap.h>




grap_t * Cgrap::addstring(grap_t *con,const char *str,unsigned int i,unsigned int j)
{
	con->getobj().balloc(i-j+1);
	con->getobj().memcpy(&str[j],i-j);
	con->getobj().get()[i-j]=0;
			
	return add(con);	
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
			addstring(new grap_t,str,i,j);
			
			i+=CString::strlen(grap);
			j=i;
		}
		
		else { i++; }
		
	}
	
	if(i>j)
	{	
		addstring(new grap_t,str,i,j);
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
			addstring(new grap_t,str,i,j);
			
			i=skipgrap(str,grap,i);
			j=i;
		}
		
		else { i++; }
		
	}
	
}

