#define NILL static_cast<const char **>(0)

class Cmsg
{
	private:
	const char **msg;
	
	public:
	Cmsg(const char **msg=NILL);
	
	
	const char ** getmsg() const;
	void setmsg(const char **msg);
	
	unsigned int getNelement() const;
	
	const char* getstr(unsigned int i) const;
	
	
};

class base_error : public Cmsg
{
	public:
	virtual int show(const char *str,unsigned int index)=0; 
};


class base_help
{
	protected:
	Cmsg item;
	Cmsg item_desc;
	
	public:
	virtual int show(int ret)=0;
	
	Cmsg& getitem();
	Cmsg& getitem_desc();
	
	void setmsg(const char **item,const char **item_desc);
	
	
	static const int RET=1;
	
};



