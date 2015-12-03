
namespace scvt
{
template <class T>
T ui2s (CString& cstr,T num,T base=10, T len=0);

template <class T>
int isUint (CString& cstr);

template <class T>
T pow2ui (T base, T pow);

template <class T>
T s2ui (CString& cstr, T base=10);

template <class T>
T isUintHex (CString& cstr);	
}

template <class T>
T scvt::ui2s(CString& cstr,T num,T base, T len)
{

  T i, j, k, l;
  char chb, che;
  if (!base)
    {
      cstr.get()[0] = 0;
      return 0;
    }

  j = num, i = 0;
  do
    {
      k = j % base;
      j /= base;
      cstr.get()[i++] = ((base == 16) && (k > 9)) ? k + 'A' - 10 : k + '0';
    }
  while (j > 0 && i < cstr.getsize());

  for (; i < len; i++)
    {
      cstr.get()[i] = '0';
    }

  l = i;
  cstr.get()[i] = 0;


  if (i > 0)
    {
      chb = cstr.get()[0];
      che = cstr.get()[i - 1];
      for (j = 0, i--; j < i; j++, i--)
	{
	  chb = cstr.get()[j];
	  che = cstr.get()[i];
	  cstr.get()[j] = che;
	  cstr.get()[i] = chb;
	}
    }

  return l;
}

template <class T>
int isUint (CString& cstr)
{
  unsigned int i;
  if (!cstr.strlen())
    return 0;
  for (i = 0; cstr.get()[i]; i++)
    {
      if (cstr.get()[i] < '0' || cstr.get()[i] > '9')
	{
	  return 0;
	}
    }
  return 1;
}

template <class T>
T scvt::pow2ui (T base, T pow)
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
T scvt::s2ui (CString& cstr, T base)
{
	T i, j, k, l;
  j = 0;
  k = 0;
  i = cstr.strlen() - 1;
  do
    {
      if (base == 16)
	{
	  l =
	    (((cstr.get()[i] >= 'A'
	       && cstr.get()[i] <= 'F') ? (cstr.get()[i] - 'A' + 10) : (cstr.get()[i] - '0')));

	  j += l * pow2ui (base, k++);
	}

      else
	{
	  j += (cstr.get()[i] - '0') * pow2ui (base, k++);
	}
    }
  while (i-- != 0);

  return j;
}

template <class T>
T scvt::isUintHex (CString& cstr)
{
  T i;
  if (cstr.strlen())
    return 0;
  for (i = 0; cstr.get()[i]; i++)
    {
      if (!((cstr.get()[i] >= '0' && cstr.get()[i] <= '9') || (cstr.get()[i] >= 'A' && cstr.get()[i] <= 'F')))
	return 0;
    }
  return 1;
}

