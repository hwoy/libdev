#include <iostream>

#include "Crandom.h"


using namespace std;

int main(void)
{
	unsigned int i;
	Cstdrandom value;
	
	for(i=0;i<10;i++)
		cout << i <<':'<< Crandom::random(1,10,value.rand()) << endl;
	
	return 0;
}
