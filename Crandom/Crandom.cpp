#include <cstdlib>

#include <Cexception.h>
#include <Crandom.h>



basic_random::~basic_random()
{
}
unsigned int basic_random::random(unsigned int min,unsigned int max)
{
	if(min>max) throw(Cexception(__FILE__,"Crandom",__PRETTY_FUNCTION__,"min>max"));
	return (rand()%(max-min+1))+min;
}

Crandom::Crandom(int seed)
{
	srand(seed);
}

Crandom::~Crandom()
{
}

void Crandom::srand(int seed)
{
	this->seed=seed;
	std::srand(seed);
}
int Crandom::getseed(void) const
{
	return seed;
}

unsigned int Crandom::rand()
{
	return std::rand();
}


Cdevrandom::Cdevrandom(const char *str)
{
	fname=str;
}



unsigned int Cdevrandom::rand()
{
	unsigned int i,j,k;
	std::ifstream fin;
	
	if(!fname) throw(Cexception(__FILE__,"Cdevrandom",__PRETTY_FUNCTION__,"NULL pointers"));
	
	fin.open(fname);
	if(fin.fail())
		return -1;
	for(k=0,j=0;j<sizeof(i);j+=sizeof(char),k++)
	fin.get(((char *)&i)[k]);
	fin.close();
	return invalid;
}

void Cdevrandom::setfname(const char *str)
{
	fname=str;
}

const char *Cdevrandom::getfname() const
{
	return fname;
}




