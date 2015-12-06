
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
	ptr=new T[block];
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
	ptr=(byte *)0;
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
	for(i=0;i<n;i++)
		static_cast<ubyte *>(s1)[i]=static_cast<cubyte *>(s2)[i];
	return s1;
}

template <class T>
void *Cmem<T>::memset(void *s, int c, unsigned int n)
{
	unsigned int i;
	for(i=0;i<n;i++)
		(static_cast<ubyte *>(s))[i]=static_cast<ubyte>(c);
	return s;
}

template <class T>
int Cmem<T>::memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned int i;
	int j;
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
class CString : public Cmem<byte>
{
	public:
	CString(const char *str=(byte *)0);
	
	
	
	byte* strcpy(const char *str);
	byte* strcat(const char *str);
	unsigned int strlen() const;
	int strcmp(const char *str) const;
	int strncmp(const char *str,unsigned int n) const;
	
	
	CString& operator=(const char *str);
	CString& operator+=(const char *str);
	CString& operator+(const char *str);
	bool operator==(const char *str) const;
	bool operator!=(const char *str) const;
	
	CString& operator=(CString& cstr);
	CString& operator+=(CString& cstr);
	CString& operator+(CString& cstr);
	bool operator==(CString& cstr) const;
	bool operator!=(CString& cstr) const;
	

	static unsigned int strlen(const char *str);
	static int strcmp(const char *str1,const char *str2);
	static int strncmp(const char *str1,const char *str2,unsigned int n);
};

std::ostream& operator <<(std::ostream& out,CString& str);
