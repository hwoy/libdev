#include <iostream>
#include "Cmsg.h"

using namespace std;

class Cerror : public base_error
{
	public:
	int showMsg(const char *str,unsigned int index)
	{
	cerr << "Error:" << index << ':' << str << ':' << getstr(index) << endl;
	
	return -index;
	}
};
class Chelp : public base_help
{
	public:
	int showHelp(unsigned int index)
{
	cerr << getitem().getstr(index) << ':' << getitem_desc().getstr(index) << endl;
	
	return -index;
}
};


static const char *errmsg[]={"Err1","Err2","Err3",NULL};


static const char *helpmsg[]={"-h1","-h2","-h3",NULL};

static const char *helpmsg_desc[]={"Help1","Help2","Help3",NULL};

int main(void)
{
	unsigned int i;
	Cerror err;
	Chelp help;
	
	err.setmsg(errmsg);
	help.setmsg(helpmsg,helpmsg_desc);

	for(i=0;i<err.getNelement();i++)
	err.showMsg("My Error",i);

	for(i=0;i<help.getitem().getNelement();i++)
	help.showHelp(i);
	
	return 0;
}

