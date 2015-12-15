#include <iostream>

#include <Clinklist.h>
#include <container.h>
using namespace std;

typedef container<int>::linklist linklist_t;

static void showdata(Clinklist< linklist_t >& list);


int main(void)
{
	int i;
	
	Clinklist< linklist_t > list;
	Clinklist< linklist_t > listp;

	cout << "<<<< Start >>>>" << endl;
	
	for(i=1;i<=5;i++)
		list.push(new linklist_t)->getobj()=i;
	
	for(i=1;i<=5;i++)
		list.insert(new linklist_t,0)->getobj()=-i;
	
	showdata(list);

	cout << "<<<< Remove >>>>" << endl;
	list.remove(4);
	list.remove(4);
	
	showdata(list);
	
	cout << "<<<< Insert >>>>" << endl;
	list.insert(new linklist_t,4)->getobj()=1;
	list.insert(new linklist_t,4)->getobj()=-1;
	
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

static void showdata(Clinklist< linklist_t >& list)
{
	linklist_t *con;
	for(con=list.getbegin();con;con=con->get(Clinklist< linklist_t >::next).get())
	{
		cout << con->getobj() << endl;
	}
	
	cout << "... Reverse ..." << endl;
	
	for(con=list.getend();con;con=con->get(Clinklist< linklist_t >::prev).get())
	{
		cout << con->getobj() << endl;
	}		
}

