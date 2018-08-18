#include <cmath>
#include <iostream>
#include <vector>

using std::sqrt; using std::ceil;
using std::cout; using std::endl;
using std::vector;

int prop_sum(int n)
{
  int sum = 1;

  //cout << "1 is a proper divisor of " << n << endl;

  if(ceil(n % 2) == 0)
    {
      for(int x = 2; x <= sqrt(n); ++x)
        {
          if(n % x == 0)
            {
              sum += x + n/x;
              //cout << x << " and " << n/x << " are both proper divisors of " << n << endl;
	      if(x*x == n) sum -= x;
            }
        }
    }
  else
    for(int x = 3; x <= sqrt(n); x+=2)
      {
        if(n % x == 0)
          {
            sum += x + n/x;
            //cout << x << " and " << n/x << " are both proper divisors of " << n << endl;
	    if(x*x == n) sum -= x;
          }
      }

  //cout << "The sum of all the proper divisors of " << n << " is " << sum << endl;

  return sum;
}

int has_ami_pair(int n)
{
  int m = prop_sum(n);
  return prop_sum(m) == n ? m : 0;
}

static const int MAX = 10000;

int main(int argc, char* argv[])
{
  vector<int> v(MAX+1, 1);

  int sum = 0;
  //int n = atoi(argv[1]);

  for(int n = 1; n != MAX; ++n)
    {
      if(n < MAX && v[n] == 1) //valid n
	{
	  v[n] = 0; //record that it has now been checked
	  
	  int m = has_ami_pair(n);
	  
	  if(m != 0 && m != n) //then n and m are amicable pairs, ***if n = m it is illegal***
	    {
	      cout << n  << " and " << m << " are an amicable pair." << endl;
	      sum += n; //add n to sum of amicable numbers under 10000
	      if(m < MAX) //then add m to sum of amicable numbers under 10000
		{
		  //cout << "Both " << n << " and " << m << " are <" << MAX << " and not equal." << endl;
		  sum += m;
		  v[m] = 0; //since we don't want to double count n and m in our sum
		}           
	    }
	}
    
      //cout << "The sum of ambicable numbers is " << sum << endl;

    }

  cout << "The sum of ambicable numbers is " << sum << endl;

  return 0;
}
