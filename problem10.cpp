#include <iostream>
#include <cmath>

using std::cout; using std::endl;
using std::sqrt;

int main()
{
  long sum = 2L, i = 3L, j;
  do
    {
      j = 3L;
      while(i % j != 0 && j <= sqrt(i)) j += 2;
      if(j > sqrt(i)) sum += i;
      i += 2;
    }
  while(i < 2000000);
  cout << sum << endl;
  return 0;
}
