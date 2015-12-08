#include <ctime>
#include <fstream>

#ifndef _CRANDOM_H
#define _CRANDOM_H
#endif

#define _DEVNAME_ "/dev/urandom"

class basic_random
{
	public:
	virtual ~basic_random();
	virtual unsigned int rand()=0;
	unsigned int random(unsigned int min,unsigned int max);
};



class Crandom : public basic_random
{
	protected:
	int seed;
	
	public:
	Crandom(int seed=time(NULL));
	~Crandom();
	void srand(int seed);
	int getseed(void) const;
	unsigned int rand();
	
	
};



class Cdevrandom : public basic_random
{	
	protected:
	const char *fname;
	
	public:
	Cdevrandom(const char *str=_DEVNAME_);
	unsigned int rand();
	
	void setfname(const char *str);
	const char *getfname() const;
	
	
	static const unsigned int invalid=-1;

	
};

