#include "Cmsg.h"

#ifndef _CHELPMSG_H
#define _CHELPMSG_H
class Chelpmsg final : public base_help
{
	public:
	int show(int ret=RET) override;
};

#endif
