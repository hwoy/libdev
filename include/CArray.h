
#ifndef _CARRAY_H
#define _CARRAY_H
template <class T>
class CArray
{
	protected:
	T *ptr;
	unsigned int size;
	
	public:
	CArray():size(0){ptr=static_cast<T *>(0);}
	
	CArray(unsigned int size){_alloc(size);}
	
	~CArray(){delete[] ptr;}
	
	T *alloc(unsigned int size)
	{
		if(ptr) destroy();
		return _alloc(size);
	}
	
	T *_alloc(unsigned int size)
	{
		this->size=size;
		return ptr=new T[size];
	}
	
	void destroy()
	{
		if(ptr)
		{
		delete[] ptr;
		size=0;
		}
	}
	
	T& get(unsigned int index){return (index+1<=size)?ptr[index]:*static_cast<T *>(0);}
	
	T* getptr(void){return ptr;}
	
	unsigned int getsize() {return size;}
	
	T& operator[] (unsigned int index){return get(index);}
	
};

#endif

