
#include "Cmsg.h"


#ifndef _CERRMSG_H
#define _CERRMSG_H
class Cerrormsg final : public base_error
{
	public:
	int show(const char *str,unsigned int index) override;
};
#endif