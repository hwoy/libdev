#include <iostream>
#include "CString.h"
#include "_scvt.h"

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
	str.balloc(33);
	
	scvt::ui2s<CString,unsigned int>(str,-1);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	scvt::ui2s<CString,unsigned short>(str,-1);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	scvt::ui2s<CString,unsigned char>(str,-1);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	cout << "== ui2s function base=16 ==" << endl;
	scvt::ui2s<CString,unsigned int>(str,-1,16);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	scvt::ui2s<CString,unsigned short>(str,-1,16);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	scvt::ui2s<CString,unsigned char>(str,-1,16);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	cout << "== ui2s function base=2 ==" << endl;
	
	scvt::ui2s<CString,unsigned int>(str,-1,2);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	scvt::ui2s<CString,unsigned short>(str,-1,2);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	scvt::ui2s<CString,unsigned char>(str,-1,2);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	str="123";
	if(scvt::isUint<CString>(str))
	{
		cout << scvt::s2ui<CString,unsigned int>(str) << " is Unsigned int" << endl;
	}
	else
	{
		cout << scvt::s2ui<CString,unsigned int>(str) << " is not Unsigned int" << endl;
	}
	
	str="123B";
	if(scvt::isUintHex<CString>(str))
	{
		cout << scvt::s2ui<CString,unsigned int>(str,16) << " is Unsigned int Hex" << endl;
	}
	else
	{
		cout << scvt::s2ui<CString,unsigned int>(str,16) << " is not Unsigned int Hex" << endl;
	}
	
	cout << endl;
	
	
	str="00001111";
	if(scvt::isUint<CString>(str))
	{
		cout << scvt::s2ui<CString,unsigned int>(str,2) << " is Unsigned int Hex" << endl;
	}
	else
	{
		cout << scvt::s2ui<CString,unsigned int>(str,2) << " is not Unsigned int Hex" << endl;
	}
	
	cout << endl;

	
	cout << "== test str=NULL = destroy() ==" << endl;
	str=NULL;
	str.balloc(33);	
	
	ui2s <unsigned int>(10001, str.get(), str.getsize(),10, 0);
	cout << str << endl;
	cout << "STR size = " << str.strlen() << endl;
	cout << "MEM size = " << str.getsize() << endl << endl;
	
	
	return 0;
}
