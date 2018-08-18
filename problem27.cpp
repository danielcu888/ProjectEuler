#include <vector>
#include<iostream>
#include <stdexcept>

using std::vector;
using std::cout;
using std::endl;
using std::domain_error;

vector<long> primes(long n)
{
  vector<long> v(n, 1L);
  
  for(long i = 2L; i != n; ++i)
    if(v[i] == 1L)
      for(long j = i; i*j < n; ++j)
	v[i*j] = 0L;

  return v;
}

static const long N = 1000000;

int main()
{
  vector<long> v = primes(N);
  long max_count = 0;
  int max_a, max_b;

  for(int a = -999; a != 1000; ++a)
    {
      for(int b = 2; b != 1000; ++b)
	{
	  long count = 0;
	  long n = 0L;
	  long num = b;

	  while(v[num] == 1L)
	    {
	      ++count;
	      ++n;
	      num = n*n + a*n + b;
	      if(num > N) 
		throw domain_error("ERROR!!!");
	    }

	  if(count > max_count)
	    {
	      max_count = count;
	      max_a = a;
	      max_b = b;
	    }

	  //cout << a << " " << b << " " << count << " " 
	  //     << max_a << " " << max_b << " " << max_count 
	  //     << endl;
	}
    }

  cout << max_a*max_b << endl;

  return 0;
}
