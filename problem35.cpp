#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using std::vector; using std::string;
using std::cout; using std::stringstream;
using std::endl; using std::atoi;

static const long N = 1000000L;

vector<long> primes(long n)
{
  vector<long> v(n, 1);

  for(long i = 2L; i != n; ++i)
    if(v[i] == 1L)
      for(long j = i; j*i < n; ++j)
	v[i*j] = 0L;
  
  return v;
}

vector<int> generate_perms(long n)
{
  stringstream ss;
  ss << n;
  string s = ss.str();
 
  vector<int> v;
  
  for(string::size_type i = 0; i != s.size(); ++i)
    {
      s = s.substr(1, s.size()-1) + s.substr(0,1);
      v.push_back(atoi(s.c_str()));
    }

  return v;
}

int main()
{
  vector<long> v = primes(N);

  long count = 0;
  for(vector<long>::size_type i = 2; i != v.size(); ++i)
    {
      if(v[i] == 1) //then i is a prime
	{
	  vector<int> w = generate_perms(i); //generae lexicographical permutations of i
	  
	  bool circular = true;
	  for(int j = 0; j != w.size(); ++j) //for all permutations of i
	    {
	      if(v[w[j]] == 0) //if jth permutation is non-prime then break
		{
		  circular = false;
		  break;
		}
	    }
	  
	  if(circular) //then all lexicographical permutations of i are prime, hence i is circularly prime
	    ++count;
	}
    }

  cout << count << endl; //outpur the result

  return 0;
}
