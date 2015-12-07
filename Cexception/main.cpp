#include <iostream>

#include <Cexception.h>
#include <CString.h>
#include <Crandom.h>



using namespace std;
int main(void)
{
unsigned int i;
Crandom rnd;
Cmem<void *> mem;
CString str;

cout << "============ Crandom ============ " << endl;
for(i=0;i<50;i++)
{
	try
	{
	cout << rnd.random(rnd.random(0,210),200)  << endl;
	}catch(Cexception &exec)
		{
			cout << exec.what() << endl;
			continue;
		}
}

cout << "\n\n============ Cmem*alloc ============ " << endl;
for(i=0;i<5;i++)
{
	try
	{
	cout << "i = " << i  << endl;
	mem.reballoc(-1);
	}catch(Cexception &exec)
		{
			cout << exec.what() << endl;
			continue;
		}
}

cout << "\n\n============ Cmem*memcpy ============ " << endl;
	try
	{
		Cmem<void *>::memcpy(NULL,NULL,100);
	}catch(Cexception &exec)
		{
			cout << exec.what() << endl;
		}
		
cout << "\n\n============ CString + ============ " << endl;
	try
	{
		str=str+"Error";
	}catch(Cexception &exec)
		{
			cout << exec.what() << endl;
		}

cout << "\n\n============ CString +=NULL ============ " << endl;
	try
	{
		str+="Error";
	}catch(Cexception &exec)
		{
			cout << exec.what() << endl;
		}
cout << "\n\n============ CString +=NULL ============ " << endl;
	try
	{
		str+=NULL;
	}catch(Cexception &exec)
		{
			cout << exec.what() << endl;
		}	
	return 0;
}

