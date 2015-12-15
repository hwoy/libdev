#include "CArray.h"
#include "Cstack.h"
#include "Clinklist.h"


#ifndef _CONTAINER_H
#define _CONTAINER_H

template <class T>
struct container
{
	typedef Ccontainer<T,2> stack;
	typedef Ccontainer<T,2> linklist;
};

#endif
