#include <Cmsg.h>

Cmsg::Cmsg(const char **msg)
{
	this->msg=msg;
}
const char ** Cmsg::getmsg() const
{
	return msg;
}

void Cmsg::setmsg(const char **msg)
{
	this->msg=msg;
}

unsigned int Cmsg::getNelement() const
{
	unsigned int i;
	for(i=0;msg[i];i++);
	
	return i;
}

const char * Cmsg::getstr(unsigned int i) const
{
	return msg[i];
}


Cmsg& base_help::getitem()
{
	return item;
}

Cmsg& base_help::getitem_desc()
{
	return item_desc;
}

void base_help::setmsg(const char **item,const char **item_desc)
{
	this->item=item;
	this->item_desc=item_desc;
}


