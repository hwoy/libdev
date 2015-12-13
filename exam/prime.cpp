#include <iostream>
#include <CString.h>
#include <_scvt.h>
#include <Cmsg.h>
#include <Copt.h>



template <class T>
bool isPrime(T num)
{
	T i;
	
	if(!num) return false;
	else if(num<=2) return true;
	
	for(i=2;(i*i)<=num;i++)
	{
		if(!(num%i)) return false;
	}
	
	return true;
}

using namespace std;

class Cerror : public base_error
{
	public:
	int show(const char *str,unsigned int index)
	{
	cerr << "Error:" << index << ':' << str << ':' << getstr(index) << endl;
	
	return -(index+1);
	}
};
class Chelp : public base_help
{
	public:
	int show(int ret=RET)
{
	unsigned int i;
	for(i=0;i<getitem().getNelement();i++)
		cerr << getitem().getstr(i) << ':' << getitem_desc().getstr(i) << endl;
	
	return ret;
}
};

class Excep
{
	protected:
	unsigned int errNO;
	bool isHelp;
	CString msg;
	
	public:
	Excep(unsigned int errNO,const char *msg,bool isHelp)
	{
		this->errNO=errNO;
		this->msg=msg;
		this->isHelp=isHelp;
	}
	
	unsigned int geterrNO() const
	{
		return errNO;
	}
	
	bool getisHelp() const
	{
		return isHelp;
	}
	
	const CString& getmsg() const
	{
		return msg;
	}
	
};




static const char *param[]={"-b:","-e:","-h",NULL};
static const char *param_desc[]={"Begin numer","End number:","-h",NULL};
enum
{
	p_b,p_e,p_h
};

static const char *errmsg[]={"Too few parameter","Not an Unsigned Number","Begin>End","Invalid an Option",NULL};
enum
{
	err_few,err_nan,err_be,err_inv
};

typedef unsigned int prime_t;

int main(int argc,const char *argv[])
{
	int i;
	unsigned int count;
	prime_t j;
	prime_t begin,end;
	
	Cerror err;
	Chelp help;
	
	Copt opt(argc,argv,param);
	err.setmsg(errmsg);
	help.setmsg(param,param_desc);
	
	begin=end=0;
	
	
	try{
		
	if(opt.getargc()<2)
		throw (Excep(err_few,"argc",true));
		
	while((i=opt.action())!=Copt::END)
	{
		switch(i)
		{
			case p_b:
			if(!scvt::isUint<Copt>(opt))
				throw (Excep(err_nan,opt.get(),false));
			
			begin=scvt::s2ui<Copt,prime_t>(opt);
			break;
			
			case p_e:
			if(!scvt::isUint<Copt>(opt))
				throw (Excep(err_nan,opt.get(),false));
			
			end=scvt::s2ui<Copt,prime_t>(opt);
			break;
			
			case p_h:
			return help.show(1);
			break;
			
			case Copt::OTHER:
			if(opt.getargc()==2 && scvt::isUint<Copt>(opt))
			{
				end=scvt::s2ui<Copt,prime_t>(opt);
				break;
			}
				
			throw (Excep(err_inv,opt.get(),true));
			
		}			
	}
	
	if(begin>end) throw (Excep(err_be,"err_be",false));
	
	
	}catch(Excep &e){ if(e.getisHelp()) {help.show(); cout << endl;}  return err.show(e.getmsg().get(),e.geterrNO());}
	
	for(count=0,j=begin;j<=end;j++)
	{
		if(isPrime<prime_t>(j))
		{
			cout << j << endl;
			count++;
		}
	}
	
	cout << endl << begin << " to " << end << " has " << count << endl;
	
	return 0;
}

