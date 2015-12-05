#include <iostream>
#include "CString.h"


unsigned int CString::strlen(const char *str)
{
	unsigned int i;
	for(i=0;str[i];i++);
	return i;
}


	int CString::strcmp(const char *str) const
	{
		return strcmp(ptr,str);
	}
	
	int CString::strcmp(const char *str1,const char *str2)
	{
		unsigned int i;
		int j;
		for(i=0;str1[i] || str2[i];i++)
		{
			j=str1[i]-str2[i];
			if(j) return j;
		}
		
		return 0;
	}
	
	int CString::strncmp(const char *str,unsigned int n) const
	{
		return strncmp(ptr,str,n);
	}
	
	int CString::strncmp(const char *str1,const char *str2,unsigned int n)
	{
		unsigned int i;
		int j;
		for(i=0;i<n;i++)
		{
			j=str1[i]-str2[i];
			if(j) return j;
		}
		
		return 0;		
	}
	
	
CString::CString(const char *str)
{
	strcpy(str);
}

unsigned int CString::strlen() const
{
	return strlen(ptr);
}


byte* CString::strcpy(const char *str)
{
	if(ptr)
		destroy();
	
	if(str)
	{
		
	balloc(strlen(str)+1);
	memcpy(str,strlen(str)+1);
	}
	
	return ptr;
}

byte* CString::strcat(const char *str)
{
	CString tmp;
	unsigned int i,j;
	tmp.balloc(strlen()+strlen(str)+1);
	
	for(i=0;ptr[i];i++)
		tmp.get()[i]=ptr[i];
	
	for(j=0;str[j];i++,j++)
		tmp.get()[i]=str[j];
	
	tmp.get()[i]=0;
	
	strcpy(tmp.get());
	
	return ptr;
	
}

CString& CString::operator=(const char *str)
{
	strcpy(str);
	return *this;
}

CString& CString::operator+=(const char *str)
{
	strcat(str);
	return *this;
}

CString& CString::operator+(const char *str)
{
	static CString cstr;
	if(this!=&cstr)
		cstr.strcpy(ptr);
	cstr.strcat(str);
	return cstr;
}

bool CString::operator==(const char *str) const
{
	return strcmp(str)?false:true;
}
bool CString::operator!=(const char *str) const
{
	return !operator==(str);
}

	CString& CString::operator=(CString& cstr)
	{
		return operator=(cstr.get());
	}
	CString& CString::operator+=(CString& cstr)
	{
		return operator+=(cstr.get());
	}
	CString& CString::operator+(CString& cstr)
	{
		return operator+(cstr.get());
	}
	
	bool CString::operator==(CString& cstr) const
	{
		return operator==(cstr.get());
	}
	bool CString::operator!=(CString& cstr) const
	{
		return operator!=(cstr.get());
	}

std::ostream& operator <<(std::ostream& out,CString& str)
{
	out << str.get();
	return out;
}

