#include <cstdlib>
#include <fstream>

#include <Cexception.h>
#include <Crandom.h>




unsigned int basic_random::random(unsigned int min,unsigned int max)
{
	return random(min,max,rand());
}

unsigned int basic_random::random(unsigned int min,unsigned int max,rand_t rand_f)
{
	if(!rand_f) throw(Cexception(__FILE__,"basic_random",__PRETTY_FUNCTION__,"NULL pointers"));
	return random(min,max,rand_f());
}
unsigned int basic_random::random(unsigned int min,unsigned int max,unsigned int value)
{
	if(min>max) throw(Cexception(__FILE__,"basic_random",__PRETTY_FUNCTION__,"min>max"));
	return (value%(max-min+1))+min;	
}


void Crandom::set(int seed) 
{
	this->seed=seed; 
	std::srand(seed);
}

unsigned int Crandom::rand()
{
	return std::rand();
}


unsigned int Cdevrandom::rand()
{
	return rand(fname);
}

unsigned int Cdevrandom::rand(const char *fname)
{
	unsigned int i,j,k;
	std::ifstream fin;
	if(!fname) throw(Cexception(__FILE__,"Cdevrandom",__PRETTY_FUNCTION__,"NULL pointers"));
	
	fin.open(fname);
	if(fin.fail())
		return invalid;
	
	for(k=0,j=0;j<sizeof(i);j+=sizeof(char),k++)
	fin.get(((char *)&i)[k]);

	fin.close();
	return i;
}





