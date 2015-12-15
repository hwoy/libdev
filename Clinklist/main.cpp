#include <iostream>

#include <Clinklist.h>
#include <container.h>
using namespace std;

typedef container<int>::linklist node_int;

static void showdata(Clinklist< node_int >& list);


int main(void)
{
	int i;
	
	Clinklist< node_int > list;
	Clinklist< node_int > listp;

	cout << "<<<< Start >>>>" << endl;
	
	for(i=1;i<=5;i++)
		list.push(new node_int)->getobj()=i;
	
	for(i=1;i<=5;i++)
		list.insert(new node_int,0)->getobj()=-i;
	
	showdata(list);

	cout << "<<<< Remove >>>>" << endl;
	list.remove(4);
	list.remove(4);
	
	showdata(list);
	
	cout << "<<<< Insert >>>>" << endl;
	list.insert(new node_int,4)->getobj()=1;
	list.insert(new node_int,4)->getobj()=-1;
	
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

static void showdata(Clinklist< node_int >& list)
{
	node_int *con;
	for(con=list.getbegin();con;con=con->get(Clinklist< node_int >::next).get())
	{
		cout << con->getobj() << endl;
	}
	
	cout << "... Reverse ..." << endl;
	
	for(con=list.getend();con;con=con->get(Clinklist< node_int >::prev).get())
	{
		cout << con->getobj() << endl;
	}		
}

