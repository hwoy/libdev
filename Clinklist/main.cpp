#include <iostream>
#include "Clinklist.h"
using namespace std;


class sam
{
	private:
	int i;
	
	public:
	
	sam(int i=0){this->i=i;}
	
	void set(int i){this->i=i;}
	
	int get() const {return i;}
	
};

int main(void)
{
	int i;
	
	Clinklist< Cdirect<int> > list;
	Cdirect<int> *dir;
	
	for(i=1;i<=5;i++)
		list.push(new Cdirect<int>)->getobj()=i;
	
	for(i=1;i<=5;i++)
		list.insert(new Cdirect<int>,0)->getobj()=-i;
	
	
	
	
	for(dir=list.getbegin();dir;dir=dir->getpos())
	{
		cout << dir->getobj() << endl;
	}
	
	cout << "... Reverse ..." << endl;
	
	for(dir=list.getend();dir;dir=dir->getneg())
	{
		cout << dir->getobj() << endl;
	}
	
	
	
	return 0;
}

