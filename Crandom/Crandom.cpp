#include <fstream>
#include <cstdlib>
#include <ctime>

#include "Crandom.h"

basic_random::~basic_random()
{
}
unsigned int basic_random::random(unsigned int min,unsigned int max)
{
	return (min<=max)?(rand()%(max-min+1))+min:-1;
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
	fin.open(str);
}

Cdevrandom::~Cdevrandom()
{
	if(!fin.fail())
	fin.close();
}

unsigned int Cdevrandom::rand()
{
	unsigned int i,j,k;
	if(fin.fail())
		return -1;
	for(k=0,j=0;j<sizeof(i);j+=sizeof(char),k++)
	fin.get(((char *)&i)[k]);
	
	return i;
}

std::ifstream& Cdevrandom::getfin()
{
	return fin;
}

std::ifstream& Cdevrandom::open(const char *str)
{
	fin.open(str);
	return fin;
}

void Cdevrandom::close()
{
	fin.close();
}

