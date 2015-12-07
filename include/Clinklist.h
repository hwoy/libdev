
#ifndef _CLINKLIST_H
#define _CLINKLIST_H
#endif

#ifndef _CEXCEPTION_H
#include "Cexception.h"
#endif

// **************  class Cdirect   ************** //
template <class T>
class Cdirect
{
	protected:
	Cdirect<T> *pos;
	Cdirect<T> *neg;
	T obj;
	
	public:
	Cdirect();
	
	Cdirect<T> *getpos();
	Cdirect<T> *getneg();
	
	
	void setpos(Cdirect<T> *pos);
	void setneg(Cdirect<T> *neg);	
	
	T& getobj();
};

template <class T>
Cdirect<T>::Cdirect()
{
	pos=static_cast<Cdirect<T> *>(0);
	neg=static_cast<Cdirect<T> *>(0);
}


template <class T>
Cdirect<T> *Cdirect<T>::getpos()
{
	return pos;
}

template <class T>
Cdirect<T> *Cdirect<T>::getneg()
{
	return neg;
}

template <class T>
void Cdirect<T>::setpos(Cdirect<T> *pos)
{
	this->pos=pos;
}

template <class T>
void Cdirect<T>::setneg(Cdirect<T> *neg)
{
	this->neg=neg;
}


template <class T>
T& Cdirect<T>::getobj()
{
	return obj;
}


// **************  class Clinklist   ************** //

template <class T>
class Clinklist
{
	protected:
	T *begin;
	T *end;
	
	T* split(T* obj);	
	
	public:
	Clinklist();
	~Clinklist();
	
	void destroy();
	void remove(unsigned int index);
	void remove(T* obj);
	
	T *getbegin() const;
	T *getend() const;
	
	unsigned int countCdirect();
	unsigned int getCdirectindex(T* obj);
	T* getCdirect(unsigned int index);
	
	T* add(T *obj);
	T* split(unsigned int index);
	
	T* push(T *obj);
	T* pop();
	
	T* insert(T *obj,unsigned int index);
	
	T* split();
	T* concat(T *obj);
	
	static const unsigned int invalid=-1;
};

template <class T>
Clinklist<T>::Clinklist()
{
	begin=static_cast<T *>(0);
	end=static_cast<T *>(0);
}

template <class T>
Clinklist<T>::~Clinklist()
{
	destroy();
}

template <class T>
void Clinklist<T>::destroy()
{
T *dir,*tmp;
	for(dir=begin;dir;)
	{
		tmp=dir;
		dir=dir->getpos();
		delete tmp;
	}
	
	begin=static_cast<T *>(0);
	end=static_cast<T *>(0);
}

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

	index=getCdirectindex(obj);
	if(index!=invalid)
		remove(index);
}

template <class T>
T *Clinklist<T>::getbegin() const
{
	return begin;
}

template <class T>
T *Clinklist<T>::getend() const
{
	return end;
}

template <class T>
T* Clinklist<T>::add(T *obj)
{
	if(!obj)
		throw(Cexception(__FILE__,"Clinklist",__PRETTY_FUNCTION__,"NULL pointers"));	
	
	obj->setpos(static_cast<T *>(0));
	obj->setneg(static_cast<T *>(0));
	return concat(obj);
}

template <class T>
T* Clinklist<T>::push(T *obj)
{
	return add(obj);
}

template <class T>
T* Clinklist<T>::pop()
{
	unsigned int i;
	
	if((i=countCdirect())) return split(i-1);
	
	return static_cast<T *>(0);
}

template <class T>
unsigned int Clinklist<T>::getCdirectindex(T* obj)
{
	unsigned int i;
	T *dir;
	for(i=0,dir=begin;dir;i++,dir=dir->getpos())
	{
		if(dir==obj) return i;
	}
	
	return invalid;
	
}

template <class T>
T* Clinklist<T>::getCdirect(unsigned int index)
{
	unsigned int i;
	T *dir;
	for(i=0,dir=begin; dir && i<index ;i++,dir=dir->getpos());
	
	return dir;
}

template <class T>
T* Clinklist<T>::split(T* obj)
{
	if(!obj)
		throw(Cexception(__FILE__,"Clinklist",__PRETTY_FUNCTION__,"NULL pointers"));
	
	if(((begin==static_cast<T *>(0)) &&(end==static_cast<T *>(0))) )
		return static_cast<T *>(0);
	
	if(begin==end)
	{
		begin=end=static_cast<T *>(0);
	}
	
	else if(begin==obj)
	{
		begin=obj->getpos();
		obj->getpos()->setneg(  obj->getneg()  );
	}
	
	else if(end==obj)
	{
		end=obj->getneg();
		obj->getneg()->setpos(  obj->getpos()  );
	}
	
	else
	{
		obj->getneg()->setpos(  obj->getpos()  );
		obj->getpos()->setneg(  obj->getneg()  );
	}
	
	return obj;
	
}


template <class T>
T* Clinklist<T>::split(unsigned int index)
{
	return split(getCdirect(index));
}

template <class T>
unsigned int Clinklist<T>::countCdirect()
{
	unsigned int i;
	T *dir;
	for(i=0,dir=begin;dir;i++,dir=dir->getpos());
	
	return i;
}

template <class T>
T* Clinklist<T>::insert(T *obj,unsigned int index)
{
	T* dir;
	if(!obj)
		throw(Cexception(__FILE__,"Clinklist",__PRETTY_FUNCTION__,"NULL pointers"));
	
	dir=getCdirect(index);
	if(!dir) return static_cast<T *>(0);
	
	if(begin==end)
	{
		add(obj);
	}
	else if(dir==begin)
	{
		dir->setneg(obj);
		obj->setpos(begin);
		begin=obj;
	}
	else
	{
		obj->setneg(dir->getneg());
		obj->setpos(dir);
		dir->getneg()->setpos(obj);
		dir->setneg(obj);
		
	}
	
	return obj;
}
template <class T>
T* Clinklist<T>::split()
{
	T* dir;
	dir=begin;
	
	begin=end=static_cast<T *>(0);
	
	return dir;
}
	
template <class T>	
T* Clinklist<T>::concat(T *obj)
{
	T* dir;
	if(!obj)
		throw(Cexception(__FILE__,"Clinklist",__PRETTY_FUNCTION__,"NULL pointers"));
	dir=obj;
	if(!begin && !end)
	{
		begin=dir;
	}
	else
	{
		dir->setneg(end);
		end->setpos(dir);
	}
	
	end=getCdirect(countCdirect()-1);

	return dir;
	
}

//////////////////////////////////


