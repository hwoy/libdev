#include <cstdlib>
#include <fstream>

#include <Cexception.h>
#include <Crandom.h>




unsigned int Crandom::random(unsigned int min,unsigned int max)
{
	return random(min,max,randfptr);
}

unsigned int Crandom::random(unsigned int min,unsigned int max,rand_t rand_f)
{
	if(!rand_f) throw(Cexception(__FILE__,"Crandom",__PRETTY_FUNCTION__,"NULL pointers"));
	return random(min,max,rand_f());
}
unsigned int Crandom::random(unsigned int min,unsigned int max,unsigned int value)
{
	if(min>max) throw(Cexception(__FILE__,"Crandom",__PRETTY_FUNCTION__,"min>max"));
	return (value%(max-min+1))+min;	
}


void Cstdrandom::set(int seed) 
{
	this->seed=seed; 
	std::srand(seed);
}

unsigned int Cstdrandom::rand()
{
	return std::rand();
}


unsigned int Cdevrandom::rand()
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




