#include <cstdlib>
#include <fstream>

#include <Cexception.h>
#include <Crandom.h>






Crandom::Crandom(int seed)
{
	srand(seed);

}

unsigned int Crandom::random(unsigned int min,unsigned int max,rand_t rand_f)
{
	if(min>max) throw(Cexception(__FILE__,"Crandom",__PRETTY_FUNCTION__,"min>max"));
	return (rand_f()%(max-min+1))+min;
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


unsigned int Crandom::devrand()
{
	unsigned int i,j,k;
	std::ifstream fin;
	
	fin.open(_DEVNAME_);
	if(fin.fail())
		return invalid;
	
	for(k=0,j=0;j<sizeof(i);j+=sizeof(char),k++)
	fin.get(((char *)&i)[k]);

	fin.close();
	return i;
}




