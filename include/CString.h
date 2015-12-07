
#ifndef _CSTRING_H
#define _CSTRING_H
#endif

#ifndef _CMEM_H
#include "Cmem.h"
#endif

class CString : public Cmem<byte>
{
	public:
	CString(const char *str=(byte *)0);
	
	
	
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
	
	CString& operator=(CString& cstr);
	CString& operator+=(CString& cstr);
	CString& operator+(CString& cstr);
	bool operator==(CString& cstr) const;
	bool operator!=(CString& cstr) const;
	

	static unsigned int strlen(const char *str);
	static int strcmp(const char *str1,const char *str2);
	static int strncmp(const char *str1,const char *str2,unsigned int n);
};

std::ostream& operator <<(std::ostream& out,CString& str);
