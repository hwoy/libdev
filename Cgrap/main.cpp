#include <iostream>
#include "../CString/CString.h"
#include "../Clinklist/Clinklist.h"
#include "Cgrap.h"

using namespace std;

static const char str[]="Hello<>Wenus<>Hwoy<><>View";
static const char grap[]="<>";

static const char str2[]="Hello       Wenus Hwoy    View  ";
static const char grap2=0x20;

int main(void)
{
Cdirect<CString> *dir;
Cgrap cgrap;

cgrap.action(str,grap);

cout << str << endl << endl;

for (dir=cgrap.getbegin();dir;dir=dir->getpos())
{
	cout << dir->getobj() << endl;
}

cgrap.destroy();
cgrap.action2(str2,grap2);

cout << str2 << endl << endl;

for (dir=cgrap.getbegin();dir;dir=dir->getpos())
{
	cout << dir->getobj() << endl;
}

	return 0;
}


