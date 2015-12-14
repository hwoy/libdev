
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
	T *point;
	
	public:
	Cdirect():point(static_cast<T *>(0)){}
	
	void set(T *point){this->point=point;}
	T* get(){return point;}
	
};

template <class T>
class CArray
{
	protected:
	unsigned int narray;
	T *array;
	
	public:
	CArray():narray(0){array=static_cast<T *>(0);}
	CArray(unsigned int narray){_alloc(narray);}
	~CArray(){delete[] array;}
	
	T *alloc(unsigned int narray)
	{
		if(array) destroy();
		return _alloc(narray);
	}
	
	T *_alloc(unsigned int narray){this->narray=narray;return array=new T[narray];}
	
	void destroy(){delete[] array;narray=0;}
	
	T& get(unsigned int index){return (index+1<=narray)?array[index]:*static_cast<T *>(0);}
	unsigned int getnarr() {return narray;}
	
};

// **************  class Ccontainer   ************** //
template <class T>
class Ccontainer : public CArray<Cdirect<Ccontainer<T> > >
{
	protected:
	T obj;

	
	public:
	Ccontainer(unsigned int ndirect=2):CArray<Cdirect<Ccontainer<T> > >::CArray(ndirect){}
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

// **************  class Clinklist   ************** /

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

//////////////////////////////////


