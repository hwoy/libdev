
class Copt : public CString
{
	protected:
	
	int argc;
	unsigned int index;
	unsigned int start;
	const char **argv;
	const char **param;
	
	public:
	static const int other=-1;
	static const int end=-2;
	static const unsigned int START=1;
	
	Copt(int argc,const char **argv=NULL,const char **param=NULL,unsigned start=START);
	
	void setup(int argc,const char **argv=NULL,const char **param=NULL,unsigned start=START);
	
	void destroy();
	
	int getindex () const;
	void setindex (unsigned index);
	
	int getstart () const;
	void setstart (unsigned int start);
	
	int getargc() const;
	void setargc(int argc);
	
	
	const char **getargv() const;
	void setargv(const char **argv);
	
	const char **getparam() const;
	void setparam(const char **param);
	unsigned int getparamcount() const;
	
	void init(int argc,const char **argv,const char **param,unsigned int start=1);
	void init(unsigned int start=1);
	
	
	int action();

};

