#include "CArray.h"
#include "Cexception.h"


#ifndef _CSTACK_H
#define _CSTACK_H
// **************  class Cdirect   ************** //

template <class T>
class Cdirect
{
	protected:
	T *point;
	
	public:
	Cdirect():point(static_cast<T *>(0)){}
	
	void set(T *point){this->point=point;}
	T* get(){return point;}
	
};


// **************  class Ccontainer   ************** //
template <class T,unsigned int N>
class Ccontainer : public CArray<Cdirect<Ccontainer<T,N> > >
{
	protected:
	T obj;

	
	public:
	Ccontainer(unsigned int ndirect=N):CArray<Cdirect<Ccontainer<T,N> > >::CArray(ndirect){}
	T& getobj() {return obj;}
	
};

// **************  class basic_data   ************** //
template <class T>
class basic_data 
{
	
	protected:
	T *begin;
	T *end;
	
	public:
	basic_data();
	~basic_data();
	void destroy();
	
	T *getbegin() const;
	T *getend() const;
	
	unsigned int countCcontainer();
	unsigned int getCcontainerindex(T* obj);
	T* getCcontainer(unsigned int index);
	
	static const unsigned int invalid=-1;
	static const unsigned int prev=0;
	static const unsigned int next=1;
	
};

template <class T>
basic_data<T>::basic_data()
{
	begin=static_cast<T *>(0);
	end=static_cast<T *>(0);
}

template <class T>
basic_data<T>::~basic_data()
{
	destroy();
}

template <class T>
void basic_data<T>::destroy()
{
T *dir,*tmp;
	for(dir=begin;dir;)
	{
		tmp=dir;
		dir=dir->get(next).get();
		delete tmp;
	}
	
	begin=static_cast<T *>(0);
	end=static_cast<T *>(0);
}

template <class T>
T *basic_data<T>::getbegin() const
{
	return begin;
}

template <class T>
T *basic_data<T>::getend() const
{
	return end;
}


template <class T>
unsigned int basic_data<T>::getCcontainerindex(T* obj)
{
	unsigned int i;
	T *dir;
	for(i=0,dir=begin;dir;i++,dir=dir->get(next).get())
	{
		if(dir==obj) return i;
	}
	
	return invalid;
	
}

template <class T>
T* basic_data<T>::getCcontainer(unsigned int index)
{
	unsigned int i;
	T *dir;
	for(i=0,dir=begin; dir && i<index ;i++,dir=dir->get(next).get());
	
	return dir;
}

template <class T>
unsigned int basic_data<T>::countCcontainer()
{
	unsigned int i;
	T *dir;
	for(i=0,dir=begin;dir;i++,dir=dir->get(next).get());
	
	return i;
}
// **************  class Cstack   ************** //

template <class T>
class Cstack : public basic_data<T>
{
	public:
	T* push(T *obj);
	T* pop();
};
 

template <class T>
T* Cstack<T>::push(T *obj)
{
	if(!obj)
		throw(Cexception(__FILE__,"Cstack",__PRETTY_FUNCTION__,"NULL pointers"));	
	
	obj->get(basic_data<T>::next).set(static_cast<T *>(0));
	obj->get(basic_data<T>::prev).set(static_cast<T *>(0));
	
	
	if(!basic_data<T>::begin && !basic_data<T>::end)
	{
		basic_data<T>::begin=obj;
	}
	else
	{
		obj->get(basic_data<T>::prev).set(basic_data<T>::end);
		basic_data<T>::end->get(basic_data<T>::next).set(obj);
	}
	
	basic_data<T>::end=obj;

	return basic_data<T>::end;
}


template <class T>
T* Cstack<T>::pop()
{
	T *dir;
	dir=static_cast<T *>(0);
	if(basic_data<T>::begin && basic_data<T>::end)
	{
		dir=basic_data<T>::end;
		basic_data<T>::end=basic_data<T>::end->get(Cstack<T>::prev).get();
		basic_data<T>::end->get(Cstack<T>::next).set(static_cast<T *>(0));
		dir->get(Cstack<T>::prev).set(static_cast<T *>(0));
	}
	
	return dir;
}


#endif

