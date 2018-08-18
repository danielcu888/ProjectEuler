#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdexcept>

using std::floor; using std::string;
using std::cout; using std::endl;
using std::find; using std::stringstream;
using std::out_of_range;

bool contains(const string& test, const string& ref)
{
  bool ret = true;
  string::const_iterator i = test.begin();
  while(ret && i != test.end())
    ret = (find(ref.begin(), ref.end(), *i++) != ref.end());
  return ret;
}

int main()
{
  bool valid = false;

  double n = 1.0;

  while(!valid)
    {
      long beg = pow(10.0, n);
      long end = floor(pow(10.0, n)*10.0/6.0);
      if(end >= 2147483647L) 
	throw out_of_range("out of range!!!");
      for(long y = beg; y <= end; ++y)
	{
	  stringstream ss;
	  ss << y;
	  string x = ss.str();
	  
	  for(long i = 2L; i <= 6L; ++i)
	    {
	      long y2 = i*y;
	      stringstream ss2;
	      ss2 << y2;
	      string x2 = ss2.str();
	      valid = contains(x2, x);
	      if(!valid)
		break;
	    }
	  
	  if(valid)
	    {
	      cout << "Result = " << y << endl;
	      return 0;
	    }
	}
      ++n;
    }

  return 0;
}
