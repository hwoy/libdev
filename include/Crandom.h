#include <ctime>

#ifndef _CRANDOM_H
#define _CRANDOM_H
#endif

#define _DEVNAME_ "/dev/urandom"

typedef unsigned int (*rand_t)(void);





class Crandom
{
	protected:
	int seed;

	
	public:
	Crandom(int seed=time(NULL));

	unsigned int random(unsigned int min,unsigned int max,rand_t rand_f=rand);
	void srand(int seed);
	int getseed(void) const;
	
	static unsigned int rand();
	static unsigned int devrand();
	
	static const unsigned int invalid=-1;
};

