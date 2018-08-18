#include <iostream>
#include <cmath>
#include <ctime>

using std::sqrt; using std::cin;
using std::cout; using std::endl;

long lpf(long n)
{
  long start = (sqrt(n) + 2 % 2); 
  if(start % 2 == 0) start++;

  for(long i = start; i != 2; i -= 2)
    {
      if(n % i == 0) //then i is a factor of n
	{
	  long j = 2L;
	  do {
	      ++j;
	    }
	  while(i % j != 0 && j <= i);
	
	  if(j == i) //then i is a prime number
	    return i;
	}
    }
}

int main()
{
  long n, ans;
  cout << "Please enter your number: ";
  cin >> n; //600851475143L
  
  time_t start, end;
  time(&start);
  int i;
  for(i = 0; i != 3000; ++i)
    ans = lpf(n);
  time(&end);

  cout << "The largest prime factor of your number is: " << ans << endl;
  cout << "Running time: " << 1000*difftime(end, start)/i << " ms." << endl; 

  return 0;
}
