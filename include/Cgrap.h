#ifndef _CGRAP_H
#define _CGRAP_H
#endif

#ifndef _CSTRING_H
#include "CString.h"
#endif

#ifndef _CLINKLIST_H
#include "Clinklist.h"
#endif

class Cgrap : public Clinklist< Cdirect<CString> >
{
	protected:
	Cdirect<CString> * addstring(Cdirect<CString> *dir,const char *str,unsigned int i,unsigned int j);
	unsigned int skipgrap(const char *str,char grap,unsigned int i);
	
	public:
	void action(const char *str,const char *grap);
	void action2(const char *str,char grap);
};

