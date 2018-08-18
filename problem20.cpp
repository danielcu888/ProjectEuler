#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <string>
#include <stdexcept>

using std::vector; using std::floor;
using std::cout; using std::endl;
using std::log10; using std::stringstream;
using std::string; using std::strtod;
using std::pow; using std::domain_error;

vector<long>::size_type max_fill(const vector<long>& v)
{
  for(size_t i = v.size() - 1; i >= 0; --i)
    if(v[i] != 0) return floor(i + 1);
}

int main(int argc, char* argv[])
{
  if(argc != 2)
    throw domain_error("Usage: <program name> <integer>");

  const vector<long>::size_type x = 1000;

  vector<long> a(x,0);
  a[0] = 1;
  vector<long>::size_type max = 1;
  size_t p;

  stringstream ss;
  ss << argv[1];
  int n;
  ss >> n;

  for (p = 1; p != n+1; ++p) 
    {
      for(vector<long>::size_type i = 0; i != x-2; ++i) //sort vector
	{
	  while(a[i] >= 10)
	    {
	      int numzeros = floor(log10(a[i]));
	      a[i] -= pow(10.0, numzeros);
	      a[i+1] += pow(10.0, numzeros-1);
	    }
	}
      
      max = max_fill(a); //reset max length
      
      for(vector<long>::size_type j = 0; j != max; ++j) //multiply elements
	a[j] *= p;
    }

  max = max_fill(a); //final sort
  for(vector<long>::size_type i = 0; i != x-2; ++i) //sort vector                                                    
    {
      while(a[i] >= 10)
	{	      
	  int numzeros = floor(log10(a[i]));
	  a[i] -= pow(10.0, numzeros);
	  a[i+1] += pow(10.0, numzeros-1);
	}
    }
  
  max = max_fill(a);
  cout << p-1 << "!" << " is: ";

  stringstream s;
  s << a[max-1];
  string sFirst;
  s >> sFirst;

  vector<long> result;
  for(string::size_type i = 0; i != sFirst.size(); ++i)
    {
      string temp = sFirst.substr(i, 1);
      long r = strtod(temp.c_str(), NULL);
      result.push_back(r);
    }

  for(size_t l = max-1; l >= 1; --l)
    result.push_back(a[l-1]);

  int sum = 0;
  for(size_t l = 0; l != result.size(); ++l)
    {
      cout << result[l];
      sum += result[l];
    }
  cout << endl;

  cout << "The sum of the digits in " << p-1 << "! is: " << sum << endl;

  return 0;
}
