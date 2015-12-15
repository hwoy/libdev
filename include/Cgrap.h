#include "CString.h"
#include "Clinklist.h"
#include "container.h"


#ifndef _CGRAP_H
#define _CGRAP_H

typedef container<CString>::linklist grap_t;

class Cgrap : public Clinklist< grap_t >
{
	protected:
	grap_t * addstring(grap_t *con,const char *str,unsigned int i,unsigned int j);
	unsigned int skipgrap(const char *str,char grap,unsigned int i);
	
	public:
	void action(const char *str,const char *grap);
	void action2(const char *str,char grap);
};


#endif

