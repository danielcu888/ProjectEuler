#include <iostream>
#include <vector>
#include <cmath>

using std::vector; using std::floor;
using std::cout; using std::endl;
using std::log10;

vector<int>::size_type max_fill(const vector<int>& v)
{
  for(size_t i = v.size() - 1; i >= 0; --i)
    if(v[i] != 0) return floor(i + 1);
}

int main()
{
  vector<int> a(1000,0);
  a[0] = 2;
  vector<int>::size_type max = 1;
  size_t p;

  for (p = 1; p != 1000; ++p) 
    {
      for(vector<int>::size_type i = 0; i != max; ++i) //sort vector
	{
	  if(a[i] >= 10)
	    {
	      do {
		a[i] -= 10;
		a[i+1] += 1;
	      } while(a[i] >= 10);
	    }
	}
      
      max = max_fill(a); //reset max length
      
      for(vector<int>::size_type j = 0; j != max; ++j) //multiply elements
	a[j] *= 2;
    }

  max = max_fill(a); //final sort
  for(vector<int>::size_type i = 0; i != max; ++i) //sort vector                                                    
    {
      if(a[i] >= 10)
	{
	  do {
	    a[i] -= 10;
	    a[i+1] += 1;
	  } while(a[i] >= 10);
	}
    }

  int sum = 0;

  max = max_fill(a); //display final result
  cout << "2^" << p+1 << " is: "; 
  for(size_t l = max; l >= 1; --l)
    { 
      cout << a[l-1] << " ";
      sum += a[l-1];
    }
  cout << endl;
  cout << "The sum of the digits in 2^" << p+1 << " is: " << sum << endl; //display sum

  return 0;
}
