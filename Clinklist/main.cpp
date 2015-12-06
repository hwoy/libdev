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

static void showdata(Clinklist< Cdirect<int> >& list);

int main(void)
{
	int i;
	
	Clinklist< Cdirect<int> > list;
	Clinklist< Cdirect<int> > listp;

	cout << "<<<< Start >>>>" << endl;
	
	for(i=1;i<=5;i++)
		list.push(new Cdirect<int>)->getobj()=i;
	
	for(i=1;i<=5;i++)
		list.insert(new Cdirect<int>,0)->getobj()=-i;
	
	showdata(list);

	cout << "<<<< Remove >>>>" << endl;
	list.remove(4);
	list.remove(4);
	
	showdata(list);
	
	cout << "<<<< Insert >>>>" << endl;
	list.insert(new Cdirect<int>,4)->getobj()=1;
	list.insert(new Cdirect<int>,4)->getobj()=-1;
	
	showdata(list);
	
	cout << "<<<< push & pop >>>>" << endl;
	for(i=1;i<=5;i++)
		listp.push(list.pop());
	
	cout << "< List >" << endl;
	showdata(list);
	cout << "< ListP >" << endl;
	showdata(listp);
	
	cout << "<<<< Concat >>>>" << endl;
	list.concat(listp.split());
	
	cout << "< List >" << endl;
	showdata(list);
	cout << "< ListP >" << endl;
	showdata(listp);
	
	
	return 0;
}

static void showdata(Clinklist< Cdirect<int> >& list)
{
	Cdirect<int> *dir;
	for(dir=list.getbegin();dir;dir=dir->getpos())
	{
		cout << dir->getobj() << endl;
	}
	
	cout << "... Reverse ..." << endl;
	
	for(dir=list.getend();dir;dir=dir->getneg())
	{
		cout << dir->getobj() << endl;
	}		
}

