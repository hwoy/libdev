#include <iostream>
#include <CString.h>
#include <_scvt.h>
#include <Copt.h>

const char *param[]={"-A:","-B:","-C",NULL};
enum
{
	p_1,p_2,p_3
};


using namespace std;
int main(int argc,const char *argv[])
{
	int i;
	unsigned int j;
	Copt opt(argc,argv,param);
	
	if(opt.getargc()==1)
	{
		for(j=0;j<opt.getparamcount();j++)
		{
			cout << opt.getparam()[j] << endl;
		}
		return 1;
	}
	
	while((i=opt.action())!=Copt::END)
	{
		switch(i)
		{
			case p_1:
			case p_2:
			case p_3:

			cout << "command:" << opt.getparam()[i] << "\tparam:" << opt.get();
			
			if(scvt::isUint<Copt>(opt)) 
				cout  << " is an Unsigned Number";
			else if(scvt::isUintHex<Copt>(opt)) 
				cout  << " is an Unsigned Heximal Number";
			
			cout << endl;
			break;
			
			case Copt::OTHER:
			cout << "Unknown:" << opt.get() << endl;
			break;
			
		}
	}
	
	return 0;
}

