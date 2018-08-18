#include <cmath>
#include <iostream>

using std::sqrt; using std::cout;
using std::endl;

int main()
{
  int count;
  long n = 2, num;

  do
    {
      num = n*(n+1)/2;
      count = 0;

      for(long i = 1; i < sqrt(num); ++i)
	if(num % i == 0) count += 2;

      if((long)sqrt(num)*(long)sqrt(num) == num)
	  ++count;

      ++n;
    }
  while(count < 501);
  
  cout << num << " has " << count << " factors." << endl;
  
  return 0;
}
