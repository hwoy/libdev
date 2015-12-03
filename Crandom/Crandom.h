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
	std::ifstream fin;
	
	public:
	Cdevrandom(const char *str=_DEVNAME_);
	~Cdevrandom();
	unsigned int rand();
	std::ifstream& getfin(); 
	std::ifstream& open(const char *str);
	void close();
	
};

