#include "Cmem.h"


#ifndef _CSTRING_H
#define _CSTRING_H
class CString : public Cmem<byte>
{
	public:
	CString(const char *str=(byte *)0);
	CString(const CString &)=default;
	
	
	
	byte* strcpy(const char *str);
	byte* strcat(const char *str);
	unsigned int strlen() const;
	int strcmp(const char *str) const;
	int strncmp(const char *str,unsigned int n) const;
	
	
	CString& operator=(const char *str);
	CString& operator+=(const char *str);
	CString& operator+(const char *str);
	bool operator==(const char *str) const;
	bool operator!=(const char *str) const;
	
	CString& operator=(const CString& cstr);
	CString& operator+=(const CString& cstr);
	CString& operator+(const CString& cstr);
	bool operator==(const CString& cstr) const;
	bool operator!=(const CString& cstr) const;
	

	static unsigned int strlen(const char *str);
	static int strcmp(const char *str1,const char *str2);
	static int strncmp(const char *str1,const char *str2,unsigned int n);
};

std::ostream& operator <<(std::ostream& out,const CString& str);

#endif

