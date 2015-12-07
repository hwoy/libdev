#ifndef _CMEM_H
#define _CMEM_H
#endif

#ifndef _CEXCEPTION_H
#include "Cexception.h"
#endif


typedef char byte;
typedef unsigned char ubyte;

typedef const char cbyte;
typedef const unsigned char cubyte;

template <class T>
class Cmem
{
	protected:
	T* ptr;
	unsigned int size;
	
	public:
	Cmem(T* ptr=(T*)0,unsigned int size=0);
	Cmem(unsigned int block);
	~Cmem();
	
	void set(T* ptr,unsigned int size);
	void set(Cmem<T> &mem);
	T* get() const;
	Cmem<T>& getCmem() const;
	
	unsigned int getsize() const;
	
	T *memcpy(const T *s2, unsigned int n);
	T *memset(int c, unsigned int n);
	int memcmp(const T *s2, unsigned int n) const;
	
	T* balloc(unsigned int block);
	T* reballoc(unsigned int block);
	void destroy();
	
	static void *memcpy(void *s1, const void *s2, unsigned int n);
	static void *memset(void *s, int c, unsigned int n);
	static int memcmp(const void *s1, const void *s2, unsigned int n);
};
template <class T>
Cmem<T>::Cmem(T* ptr,unsigned int size)
{
	set(ptr,size);
}

template <class T>
Cmem<T>::Cmem(unsigned int block)
{
	balloc(block);
}

template <class T>
Cmem<T>::~Cmem()
{
	if(ptr) delete[] ptr;
}

template <class T>
unsigned int Cmem<T>::getsize() const
{
	return size;
}

template <class T>
T* Cmem<T>::balloc(unsigned int block)
{
	
		try
	{
	ptr=new T[block];
	}catch(std::exception &ex)
	{
		throw(Cexception(__FILE__,"Cmem",__PRETTY_FUNCTION__,ex.what()));
	}
	
	size=(sizeof(T)*block);
	return ptr;
}

template <class T>
T* Cmem<T>::reballoc(unsigned int block)
{
	if(ptr) destroy();

	return balloc(block);
}

template <class T>
void Cmem<T>::destroy()
{
	delete[] ptr;
	ptr=(T *)0;
	size=0;
}

template <class T>
void Cmem<T>::set(T* ptr,unsigned int size)
{
	this->ptr=ptr;
	this->size=size;
}

template <class T>
void Cmem<T>::set(Cmem<T> &mem)
{
	set(mem.ptr,mem.size);
}

template <class T>
T* Cmem<T>::get() const
{
	return ptr;
}

template <class T>
Cmem<T>& Cmem<T>::getCmem() const
{
	return *this;
}

//////////////////////////////////////////////////////////
template <class T>
void *Cmem<T>::memcpy(void *s1, const void *s2, unsigned int n)
{
	unsigned int i;
	
	if(!s1 || !s2)
		throw(Cexception(__FILE__,"Cmem",__PRETTY_FUNCTION__,"NULL pointers"));
	
	for(i=0;i<n;i++)
		static_cast<ubyte *>(s1)[i]=static_cast<cubyte *>(s2)[i];
	return s1;
}

template <class T>
void *Cmem<T>::memset(void *s, int c, unsigned int n)
{
	unsigned int i;
	
	if(!s)
		throw(Cexception(__FILE__,"Cmem",__PRETTY_FUNCTION__,"NULL pointers"));
	
	
	for(i=0;i<n;i++)
		(static_cast<ubyte *>(s))[i]=static_cast<ubyte>(c);
	return s;
}

template <class T>
int Cmem<T>::memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned int i;
	int j;
	
	if(!s1 || !s2)
		throw(Cexception(__FILE__,"Cmem",__PRETTY_FUNCTION__,"NULL pointers"));
	
	for(i=0;i<n;i++)
	{
		j=static_cast<int>(static_cast<byte>((static_cast<ubyte *>(s1))[i]-(static_cast<ubyte *>(s2))[i]));
		if(j) return j;
	}
return 0;	
}

/////////////////////////////////////////////////////////

template <class T>
T *Cmem<T>::memcpy(const T *s2, unsigned int n)
{
	return static_cast<T*>(memcpy(ptr,s2,n));
}

template <class T>
T *Cmem<T>::memset(int c, unsigned int n)
{
	return static_cast<T*>(memset(ptr,c,n));
}

/////////////////////////////////////////////////////////
