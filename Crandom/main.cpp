#include <iostream>
#include <fstream>
#include <ctime>
#include "Crandom.h"

using namespace std;

int main(void)
{
	unsigned int i;
	Crandom rnd;
	
	for(i=0;i<10;i++)
		cout << i <<':'<< rnd.random(1,10) << endl;
	
	return 0;
}
