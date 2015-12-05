#include <iostream>
#include "CString.h"
#include "scvt.h"
#include "function.h"

using namespace std;
int main(void)
{
	CString str="Opreation=",str2;
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	str+=" Opreation+=";
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	
	str=str+" Opreation+";
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	
	str2=str="Hello";
	
	if(str=="Hello" && str==str2)
	{
	str=str+" Opreation==";
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	}
	
	str="Hello";
	
	if(str!="Hello1")
	{
	str=str+" Opreation!=";
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	}
	
	
	cout << "== ui2s function base=10 ==" << endl;
	str.destroy();
	str.balloc(32);
	
	scvt::ui2s<unsigned int>(str,-1);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	scvt::ui2s<unsigned short>(str,-1);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	scvt::ui2s<unsigned char>(str,-1);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	cout << "== ui2s function base=16 ==" << endl;
	scvt::ui2s<unsigned int>(str,-1,16);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	scvt::ui2s<unsigned short>(str,-1,16);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	scvt::ui2s<unsigned char>(str,-1,16);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	cout << "== ui2s function base=2 ==" << endl;
	
	scvt::ui2s<unsigned int>(str,-1,2);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	scvt::ui2s<unsigned short>(str,-1,2);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	scvt::ui2s<unsigned char>(str,-1,2);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;

	
	cout << "== test str=NULL = destroy() ==" << endl;
	str=NULL;
	str.balloc(32);	
	
	ui2s (10001, str.get(), str.getsize(),10, 0);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	
	return 0;
}
