#include <iostream>
#include <string>
#include <cstddef>
#include <sstream>
#include <vector>
#include <cmath>

using std::cout; using std::endl;
using std::string; using std::size_t;
using std::stringstream; using std::strtol;
using std::vector; using std::log10;

static const string base[] = {"1","2","3","4","5","6","7","8","9"};

string write_number(long x)
{
  stringstream ss;
  ss << x;
  string ret = ss.str();
  return ret;
}

int main()
{
  string s;
  vector<long> v;
  for(size_t i = 0; s.size() <= 1000000; ++i)
    {
      s += write_number(i);
      if(i != 0 && log10((double)i) - (int)log10((double)i) == 0)
	{
	  v.push_back(strtol(s.substr(i,1).c_str(), NULL, 0)); 
	  cout << i << " " << s[i] << endl;
	}
    }
  
  long result = 1;
  for(vector<long>::size_type i = 0; i != v.size(); ++i)
    result *= v[i];

  cout << result << endl;

  return 0;
}
