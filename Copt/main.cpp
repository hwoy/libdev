#include <iostream>
#include "../CString/CString.h"
#include "Copt.h"

const char *param[]={"-A:","-B:","-C",NULL};
enum
{
	p_1,p_2,p_3
};

const char *param2[]={"-D:","-E:","-F",NULL};

using namespace std;
int main(int argc,const char *argv[])
{
	int i;
	unsigned int j;
	Copt opt(argc,argv,param);
	
	opt.init(argc,argv,param2);
	
	if(opt.getargc()==1)
	{
		for(j=0;j<opt.getparamcount();j++)
		{
			cout << opt.getparam()[j] << endl;
		}
		return 1;
	}
	
	opt.reballoc(4);
	
	while((i=opt.action())!=Copt::end)
	{
		switch(i)
		{
			case p_1:
			case p_2:
			case p_3:

			cout << "command:" << opt.getparam()[i] << "\tparam:" << opt.get() << endl;
			break;
			
			case Copt::other:
			cout << "Unknown:" << opt.get() << endl;
			break;
			
		}
	}
	
	return 0;
}

