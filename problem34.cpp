#include <iostream>
#include <cmath>
#include <sstream>
#include <string>

using std::cout; using std::endl;
using std::pow; using std::stringstream;
using std::string; using std::atoi;

int fact(int x)
{
  if(x != 0)
    {
      int ret = 1;
      for(int i = x; i != 1; --i) ret *= i;
      return ret;
    }
  else
    return 1;
}

int max_decade()
{
  double n = 1.0;
  double lim = fact(9);
  while(pow(10.0, n)/n < lim)
    ++n;
  return n;
}

static const int MAX = pow(10.0,max_decade());

int main(int argc, char* argv[])
{
  int total = 0;
  
  for(int i = 3; i != MAX; ++i)
    {
      //cout << i << endl;

      int sum = 0;
      stringstream ss;
      ss << i;
      string tmp = ss.str();
      //cout << tmp << endl;
      for(string::size_type j = 0; j != tmp.size(); ++j)
	{
	  //cout << atoi(tmp.substr(j,1).c_str()) << " " << fact(atoi(tmp.substr(j,1).c_str())) << endl;
	  sum += fact(atoi(tmp.substr(j,1).c_str()));
	  if(sum > i) break;
	}
      //cout << sum << endl;
      if(sum == i) 
	{
	  cout << i << endl;
	  total += i;
	}
    }

  cout << total << endl;

  return 0;
}
