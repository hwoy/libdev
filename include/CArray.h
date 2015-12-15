
#ifndef _CARRAY_H
#define _CARRAY_H
#endif



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
