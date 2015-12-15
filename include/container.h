#ifndef _CARRAY_H
#include "CArray.h"
#endif

#ifndef _CSTACK_H
#include "Cstack.h"
#endif

#ifndef _CLINKLIST_H
#include "Clinklist.h"
#endif

#ifndef _CONTAINER_H
#define _CONTAINER_H

template <class T>
struct container
{
	typedef Ccontainer<T,2> stack;
	typedef Ccontainer<T,2> linklist;
};

#endif
