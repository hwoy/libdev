#include <iostream>

#include "Crandom.h"


using namespace std;

int main(void)
{
	unsigned int i;
	Crandom rnd;
	
	for(i=0;i<20;i++)
		cout << i <<':'<< rnd.random(0,200) << endl;
	
	return 0;
}
