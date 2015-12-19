#include <iostream>
#include <Cmsg.h>

using namespace std;

class Cerror final : public base_error
{
	public:
	int show(const char *str,unsigned int index) override
	{
	cerr << "Error:" << index << ':' << str << ':' << getstr(index) << endl;
	
	return -(index+1);
	}
};
class Chelp final : public base_help
{
	public:
	int show(int ret=RET) override
{
	unsigned int i;
	for(i=0;i<getitem().getNelement();i++)
		cerr << getitem().getstr(i) << ':' << getitem_desc().getstr(i) << endl;
	
	return ret;
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
	err.show("My Error",i);

	help.show();
	
	return 0;
}

