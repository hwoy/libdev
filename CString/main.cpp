#include <iostream>
#include "CString.h"
#include "scvt.h"
#include "function.h"

using namespace std;
int main(void)
{
	CString str="Hello World!";
	cout << str << endl;
	str+=" My name is Hwoy";
	cout << str << endl;
	cout << str.getsize() << endl;
	
	str.destroy();
	str.balloc(32);
	
	scvt::ui2s<unsigned char>(str,-1);
	cout << str << endl;
	(str="Hello World!")+=" Fuck you!";
	cout << str << endl;

	str.destroy();
	str.balloc(32);	
	ui2s (10001, str.get(), str.getsize(),10, 0);
	cout << str << endl;
	
	str=str+" Dogs";
	cout << str << endl;
	
	return 0;
}
