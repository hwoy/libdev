#include <iostream>
#include <Chelpmsg.h>
#include <Cerrmsg.h>

using namespace std;


int Cerrormsg::show(const char *str,unsigned int index)
{
	cerr << "Error:" << index << ':' << str << ':' << getstr(index) << endl;
	
	return -(index+1);
}


int Chelpmsg::show(int ret)
{
	unsigned int i;
	for(i=0;i<getitem().getNelement();i++)
		cerr << getitem().getstr(i) << ':' << getitem_desc().getstr(i) << endl;
	
	return ret;
}


static const char *errmsg[]={"Err1","Err2","Err3",NULL};


static const char *helpmsg[]={"-h1","-h2","-h3",NULL};

static const char *helpmsg_desc[]={"Help1","Help2","Help3",NULL};

int main(void)
{
	unsigned int i;
	Cerrormsg err;
	Chelpmsg help;
	
	err.setmsg(errmsg);
	help.setmsg(helpmsg,helpmsg_desc);

	for(i=0;i<err.getNelement();i++)
	err.show("My Error",i);

	help.show();
	
	return 0;
}

