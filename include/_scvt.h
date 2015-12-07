
#ifndef __SCVT_H
#define __SCVT_H
#endif


#ifndef _CEXCEPTION_H
#include "Cexception.h"
#endif



template <class T>
T sLen (const char *ch);

template <class T>
T ui2s(T num,char * str, T bsize,T base=10, T len=0);

bool isUint (const char * str);

template <class T>
T pow2ui (T base, T pow);

template <class T>
T s2ui (const char * str, T base=10);

bool isUintHex (const char * str);

/////////////////////////
template <class T>
T sLen (const char *ch)
{
  unsigned int i;
  
  if(!ch)
	  throw(Cexception(__FILE__,"",__PRETTY_FUNCTION__,"NULL pointers"));

  for (i = 0; ch[i]; i++);
  return i;
}

template <class T>
T ui2s(T num,char * str, T bsize,T base, T len)
{

  T i, j, k, l;
  char chb, che;
  
   if(!str)
	  throw(Cexception(__FILE__,"",__PRETTY_FUNCTION__,"NULL pointers"));
  
  
  if (!base)
    {
      str[0] = 0;
      return 0;
    }

  j = num, i = 0;
  do
    {
      k = j % base;
      j /= base;
      str[i++] = ((base == 16) && (k > 9)) ? k + 'A' - 10 : k + '0';
    }
  while (j > 0 && i < bsize);

  for (; i < len; i++)
    {
      str[i] = '0';
    }

  l = i;
  str[i] = 0;


  if (i > 0)
    {
      chb = str[0];
      che = str[i - 1];
      for (j = 0, i--; j < i; j++, i--)
	{
	  chb = str[j];
	  che = str[i];
	  str[j] = che;
	  str[i] = chb;
	}
    }

  return l;
}


bool isUint (const char * str)
{
  unsigned int i;
  if (!sLen<unsigned int>(str))
    return false;
  for (i = 0; str[i]; i++)
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  return false;
	}
    }
  return true;
}

template <class T>
T pow2ui (T base, T pow)
{
  T i, j;
  if (!base)
    return 0;
  if (!pow)
    return 1;
  for (i = 1, j = base; i < pow; i++)
    {
      j = j * base;
    }
  return j;
}

template <class T>
T s2ui (const char * str, T base)
{
	T i, j, k, l;
  j = 0;
  k = 0;
  i = sLen<T>(str) - 1;
  do
    {
      if (base == 16)
	{
	  l =
	    (((str[i] >= 'A'
	       && str[i] <= 'F') ? (str[i] - 'A' + 10) : (str[i] - '0')));

	  j += l * pow2ui (base, k++);
	}

      else
	{
	  j += (str[i] - '0') * pow2ui (base, k++);
	}
    }
  while (i-- != 0);

  return j;
}

bool isUintHex (const char * str)
{
  unsigned int i;
  if (!sLen<unsigned int>(str))
    return false;
  for (i = 0; str[i]; i++)
    {
      if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F')))
	return false;
    }
  return true;
}

//////////////////////
namespace scvt
{
template <class U,class T>
T ui2s (U& cstr,T num,T base=10, T len=0);

template <class U>
bool isUint (U& cstr);

template <class T>
T pow2ui (T base, T pow);

template <class U,class T>
T s2ui (U& cstr, T base=10);

template <class U>
bool isUintHex (U& cstr);

}

/////////////////////////

template <class U,class T>
T scvt::ui2s (U& cstr,T num,T base, T len)
{
	return ::ui2s<T>(num,cstr.get(),cstr.getsize(),base,len);
}

template <class U>
bool scvt::isUint (U& cstr)
{
	return ::isUint (cstr.get());
}

template <class T>
T scvt::pow2ui (T base, T pow)
{
	return ::pow2ui<T> (base,pow);
}

template <class U,class T>
T scvt::s2ui (U& cstr, T base)
{
	return ::s2ui<T> (cstr.get(), base);
}

template <class U>
bool scvt::isUintHex (U& cstr)
{
	return ::isUintHex (cstr.get());
}

