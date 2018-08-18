#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

using std::ifstream; using std::max;
using std::cout; using std::endl;
using std::string; using std::strtod;

int main()
{
  ifstream infile("./long_num.txt");
  string s, line;
  double maxnum = 0;

  while(getline(infile, line))
    s += line;

  //cout << s << endl;

  for(string::size_type i = 0; i != s.size() - 5; ++i)
    {
      double test = strtod(s.substr(i,1).c_str(), NULL)
	*strtod(s.substr(i+1,1).c_str(), NULL)
	*strtod(s.substr(i+2,1).c_str(), NULL)
	*strtod(s.substr(i+3,1).c_str(), NULL)
	*strtod(s.substr(i+4,1).c_str(), NULL);

      /*cout << strtod(s.substr(i,1).c_str(), NULL) << " " 
	   << strtod(s.substr(i+1,1).c_str(), NULL) << " "
	   << strtod(s.substr(i+2,1).c_str(), NULL) << " "
	   << strtod(s.substr(i+3,1).c_str(), NULL) << " "
	   << strtod(s.substr(i+4,1).c_str(), NULL) << " "
	   << test << endl;
      */

      maxnum = max(maxnum, test);
    }

  cout << maxnum << endl;
  
  return 0;
}
