#include <iostream>
#include <cmath>

using std::sqrt;
using std::cout; using std::endl;

int gcd(int i1, int i2)
{
  int ret, mx = i1 > i2 ? sqrt(i1)+1 : sqrt(i2)+1;
  for(int i = 1; i <= mx; ++i)
    if(i1 % i == 0 && i2 % i == 0)
      ret = i;
  return ret;
}

int main()
{
  int num = 1, den = 1;

  for(int i = 1; i != 10; ++i)
    for(int d = 1; d < i; ++d)
      for(int n = 1; n < d; ++n)
	if((10*n + i)*d == n*(10*i + d))
	  {
	    num *= n;
	    den *= d;
	  }
  cout << den/gcd(num, den) << endl;
  return 0;
}
