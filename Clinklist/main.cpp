#include <iostream>

#include <Clinklist.h>
using namespace std;

static void showdata(Clinklist< Ccontainer<int> >& list);

int main(void)
{
	int i;
	
	Clinklist< Ccontainer<int> > list;
	Clinklist< Ccontainer<int> > listp;

	cout << "<<<< Start >>>>" << endl;
	
	for(i=1;i<=5;i++)
		list.push(new Ccontainer<int>)->getobj()=i;
	
	for(i=1;i<=5;i++)
		list.insert(new Ccontainer<int>,0)->getobj()=-i;
	
	showdata(list);

	cout << "<<<< Remove >>>>" << endl;
	list.remove(4);
	list.remove(4);
	
	showdata(list);
	
	cout << "<<<< Insert >>>>" << endl;
	list.insert(new Ccontainer<int>,4)->getobj()=1;
	list.insert(new Ccontainer<int>,4)->getobj()=-1;
	
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

static void showdata(Clinklist< Ccontainer<int> >& list)
{
	Ccontainer<int> *dir;
	for(dir=list.getbegin();dir;dir=dir->getdir(Clinklist< Ccontainer<int> >::next)->get())
	{
		cout << dir->getobj() << endl;
	}
	
	cout << "... Reverse ..." << endl;
	
	for(dir=list.getend();dir;dir=dir->getdir(Clinklist< Ccontainer<int> >::prev)->get())
	{
		cout << dir->getobj() << endl;
	}		
}

