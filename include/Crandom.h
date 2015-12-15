#ifndef _CRANDOM_H
#define _CRANDOM_H

#include <ctime>
#define _DEVNAME_ "/dev/urandom"

typedef unsigned int (*rand_t)(void);





class basic_random
{
	
	public:
	
	virtual unsigned int rand()=0;
	unsigned int random(unsigned int min,unsigned int max);
	
	static unsigned int random(unsigned int min,unsigned int max,rand_t rand_f);
	static unsigned int random(unsigned int min,unsigned int max,unsigned int value);
};

class Crandom: public basic_random
{
	protected:
	int seed;

	
	public:
	Crandom(int seed=time(NULL)) {set(seed);}

	void set(int seed);
	int get(void) const {return seed;}
	
	unsigned int rand();
};

class Cdevrandom: public basic_random
{
	protected:
	const char *fname;

	
	public:
	Cdevrandom(const char *str=_DEVNAME_):fname(str){}

	void set(const char *str) {fname=str;}
	const char *get() const {return fname;}
	
	unsigned int rand();
	
	static unsigned int rand(const char *fname);
	static const unsigned int invalid=-1;
};




#endif

