#include <cmath>
#include <iostream>
#include <vector>

using std::sqrt;
using std::cout; using std::endl;
using std::vector;

int prop_sum(int n)
{
  int sum = 1; //every number has 1 as their proper divisors
  
  if(n % 2 == 0) //if n is even ...
    {
      //cout << n << " is even" << endl;
      for(int x = 2; x <= sqrt(n); ++x) //then has both even and odd proper divisors up to sqrt(n)
	{
	  if(n % x == 0) //if true, then x and n/x are proper divisors of n 
	    {
	      sum += x + n/x; 
	      if(x*x == n) sum -= x; //if x^2 = n, then we have double counted x, so we must remove x from sum
	    }
	}
    }
  else //n is odd ...
    {
      //cout << n << " is odd" << endl;
      for(int x = 3; x <= sqrt(n); x+=2) //and therefore must be a product of an odd number and an even number
	{                                //hence if we test only odd proper divisors, x, we will automatically find
	  if(n % x == 0)
	    {
	      sum += x + n/x;
	      if(x*x == n) sum -= x; //if x^2 = n, then we have double counted x, so we must remove x from sum
	    }
	}            
    }

  return sum;
}

static const int FIRST = 12;
static const int LAST = 28124;

int main()
{
  vector<int> abun;  //contains the abundant numbers
  for(int i = 1; i != LAST; ++i) //find all abundant numbers
    if(prop_sum(i) > i) 
      abun.push_back(i);

  //for(int i = 0; i != abun.size(); ++i)
  //  cout << abun[i] << endl;

  vector<int> q(LAST, 0); //abundant numbers 0 through 28123 have element of 1, others 0
  vector<int> p(LAST, 0); //numbers 0 through 28123 writable as sum of two abundant numbers have element of 1, others 0
  for(vector<int>::size_type i = 0; i != abun.size(); ++i)
    {
      q[abun[i]] = 1;
      if(2*abun[i] < LAST) p[2*abun[i]] = 1; 
    }

  //for(int i = 0; i != q.size(); ++i)
  //  cout << i << " " << q[i] << endl;

  //for(int i = 0; i != p.size(); ++i)
  //  cout << i << " " << p[i] << endl;

  for(vector<int>::size_type x = 25; x != LAST; ++x) //test each if they are sum of 2 abundant numbers
  //int x = LAST-1;
    {
      //determine largest abundant number < x
      int i = 0;
      while(abun[i] < x && i != abun.size())
	++i;

      //largest abundant number z < x is then abun[i-1]

      //cout << "The " << i - 1 << " element of abun, equal to " << abun[i-1] 
      //   << " is the largest abundant number less than " << x << endl;

      //for the abundant numbers y <= z, test whether the difference, diff = x-y
      //is equal to an abundant number (i.e. q[diff] = 1)
      //if so, for any y, then x is the sum of 2 abundant numbers, so set its value in p to 1 and break loop
      while(i > 0)
	{
	  //cout << "i = " << i << endl;
	  int y = abun[i-1];
	  //cout << "y = abun[i -1] = " << y << endl;
	  int diff = x - y;
	  //cout << "x - y = " << diff << endl;
	  //cout << "q[x-y] = " << q[diff] << endl;
	  if(q[diff] == 1)
	    {
	      p[x] = 1;
	      //cout << "so we write p[" << x << "] = " << p[x] 
	      //<< ", since " << x << " can be written as the sum of 2 abundant numbers, "
	      //<< "and we break" << endl;
	      break;
	    }
	  //cout << "so we continue" << endl;
	  --i;
	}
      //cout << "now we have stopped" << endl;
    }

  //Now all numbers 0 < x < LAST that can be written as the sum of two abundant numbers have p[x] = 1
  //So now we sum all the numbers, y, in the vector p that have p[y] = 0
  int sum = 0;
  for(vector<int>::size_type i = 0; i != p.size(); ++i)
    if(p[i] == 0) 
      {
	sum += i;
	//cout << i << endl;
      }
  
  cout << "result = " << sum << endl;

  return 0;
}
