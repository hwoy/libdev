#include <iostream>
#include <Cgrap.h>

using namespace std;

static const char str[]="Hello<>Wenus<>Hwoy<><>View";
static const char grap[]="<>";

static const char str2[]="Hello       Wenus Hwoy    View  ";
static const char grap2=0x20;

int main(void)
{
Ccontainer<CString> *con;
Cgrap cgrap;

cgrap.action(str,grap);

cout << str << endl << endl;

for (con=cgrap.getbegin();con;con=con->getdir(basic_data<Ccontainer<CString> >::next)->get())
{
	cout << con->getobj() << endl;
}

cgrap.destroy();
cgrap.action2(str2,grap2);

cout << str2 << endl << endl;

for (con=cgrap.getbegin();con;con=con->getdir(basic_data<Ccontainer<CString> >::next)->get())
{
	cout << con->getobj() << endl;
}

	return 0;
}


