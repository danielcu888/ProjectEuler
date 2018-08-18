#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

using std::equal; using std::string;
using std::cout; using std::endl;
using std::stringstream;

bool is_pallindrone(const string& s)
{
  return equal(s.begin(), s.end(), s.rbegin());
}

int main()
{
  int result = 0;

  for(int i = 999; i != 99; --i)
    {
      for(int j = 999; j != i; --j)
	{
	  if(result >= i*j)
	    break;
	  
	  int temp = i*j;
	  stringstream out;
	  out << temp;
	  string s = out.str();
	  string t = s;
	  
	  for(string::size_type k = s.size()-1; k != -1; --k)
	  t += s[k];
	  
	  if(is_pallindrone(s))
	    result = i*j;
	}
    }
 
  cout << result << endl;

  return 0;
}
