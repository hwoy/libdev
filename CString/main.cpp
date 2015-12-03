#include <iostream>
#include "CString.h"
#include "scvt.h"

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
	str="Hello World!";
	cout << str << endl;
}
