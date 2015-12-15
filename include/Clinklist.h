#ifndef _CARRAY_H
#include "CArray.h"
#endif

#ifndef _CSTACK_H
#include "Cstack.h"
#endif


#ifndef _CEXCEPTION_H
#include "Cexception.h"
#endif


#ifndef _CLINKLIST_H
#define _CLINKLIST_H


template <class T>
class Clinklist :public Cstack <T>
{
	protected:
	
	T* split(T* obj);	
	
	public:

	void remove(unsigned int index);
	void remove(T* obj);
	
	T* add(T *obj);
	T* split(unsigned int index);
	
	T* insert(T *obj,unsigned int index);
	
	T* split();
	T* concat(T *obj);
	
};


template <class T>
void Clinklist<T>::remove(unsigned int index)
{
	T* dir;
	dir=split(index);
	if(dir) delete dir;
}

template <class T>
void Clinklist<T>::remove(T* obj)
{
	unsigned int index;

	index=getCcontainerindex(obj);
	if(index!=Cstack<T>::invalid)
		remove(index);
}


template <class T>
T* Clinklist<T>::add(T *obj)
{
	return Cstack<T>::push(obj);
}


template <class T>
T* Clinklist<T>::split(T* obj)
{
	if(!obj)
		throw(Cexception(__FILE__,"Clinklist",__PRETTY_FUNCTION__,"NULL pointers"));
	
	if(((Cstack<T>::begin==static_cast<T *>(0)) &&(Cstack<T>::end==static_cast<T *>(0))) )
		return static_cast<T *>(0);
	
	if(Cstack<T>::begin==Cstack<T>::end)
	{
		Cstack<T>::begin=Cstack<T>::end=static_cast<T *>(0);
	}
	
	else if(Cstack<T>::begin==obj)
	{
		Cstack<T>::begin=obj->get(Cstack<T>::next).get();
		obj->get(Cstack<T>::next).get()->get(Cstack<T>::prev).set(  obj->get(Cstack<T>::prev).get()  );
	}
	
	else if(Cstack<T>::end==obj)
	{
		Cstack<T>::end=obj->get(Cstack<T>::prev).get();
		obj->get(Cstack<T>::prev).get()->get(Cstack<T>::next).set(  obj->get(Cstack<T>::next).get()  );
	}
	
	else
	{
		obj->get(Cstack<T>::prev).get()->get(Cstack<T>::next).set(  obj->get(Cstack<T>::next).get()  );
		obj->get(Cstack<T>::next).get()->get(Cstack<T>::prev).set(  obj->get(Cstack<T>::prev).get() );
	}
	
	return obj;
	
}


template <class T>
T* Clinklist<T>::split(unsigned int index)
{
	return split(Cstack<T>::getCcontainer(index));
}


template <class T>
T* Clinklist<T>::insert(T *obj,unsigned int index)
{
	T* dir;
	if(!obj)
		throw(Cexception(__FILE__,"Clinklist",__PRETTY_FUNCTION__,"NULL pointers"));
	
	dir=Cstack<T>::getCcontainer(index);
	if(!dir) return static_cast<T *>(0);
	
	if(Cstack<T>::begin==Cstack<T>::end)
	{
		add(obj);
	}
	else if(dir==Cstack<T>::begin)
	{
		dir->get(Cstack<T>::prev).set(obj);
		obj->get(Cstack<T>::next).set(Cstack<T>::begin);
		Cstack<T>::begin=obj;
	}
	else
	{
		obj->get(Cstack<T>::prev).set(dir->get(Cstack<T>::prev).get());
		obj->get(Cstack<T>::next).set(dir);
		dir->get(Cstack<T>::prev).get()->get(Cstack<T>::next).set(obj);
		dir->get(Cstack<T>::prev).set(obj);
		
	}
	
	return obj;
}
template <class T>
T* Clinklist<T>::split()
{
	T* dir;
	dir=Cstack<T>::begin;
	
	Cstack<T>::begin=Cstack<T>::end=static_cast<T *>(0);
	
	return dir;
}
	
template <class T>	
T* Clinklist<T>::concat(T *obj)
{
	T* dir;
	if(!obj)
		throw(Cexception(__FILE__,"Clinklist",__PRETTY_FUNCTION__,"NULL pointers"));
	dir=obj;
	if(!Cstack<T>::begin && !Cstack<T>::end)
	{
		Cstack<T>::begin=dir;
	}
	else
	{
		dir->get(Cstack<T>::prev).set(Cstack<T>::end);
		Cstack<T>::end->get(Cstack<T>::next).set(dir);
	}
	
	Cstack<T>::end=Cstack<T>::getCcontainer(Cstack<T>::countCcontainer()-1);

	return dir;
	
}

#endif

