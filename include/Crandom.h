#include <ctime>

#ifndef _CRANDOM_H
#define _CRANDOM_H
#endif

#define _DEVNAME_ "/dev/urandom"

typedef unsigned int (*rand_t)(void);





class Crandom
{
	protected:
	rand_t randfptr;
	
	public:
	Crandom(rand_t ptr=NULL):randfptr(ptr){}
	
	void set(rand_t ptr) {randfptr=ptr;}
	rand_t get() {return randfptr;}
	
	unsigned int random(unsigned int min,unsigned int max);
	
	static unsigned int random(unsigned int min,unsigned int max,rand_t rand_f);
	static unsigned int random(unsigned int min,unsigned int max,unsigned int value);
};

class Cstdrandom
{
	protected:
	int seed;

	
	public:
	Cstdrandom(int seed=time(NULL)) {set(seed);}

	void set(int seed);
	int get(void) const {return seed;}
	
	unsigned int rand();
	
};

class Cdevrandom
{
	protected:
	const char *fname;

	
	public:
	Cdevrandom(const char *str=_DEVNAME_):fname(str){}

	void set(const char *str) {fname=str;}
	const char *get() const {return fname;}
	
	unsigned int rand();
	
	
	static const unsigned int invalid=-1;
};



