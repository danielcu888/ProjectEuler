#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::pow; using std::cout;
using std::endl; using std::string;
using std::stringstream; using std::vector;
using std::strtod;

int main()
{
  double pwr = 5.0;
  double N = 0.0, tmp1, tmp2;
  do{
    ++N;
    tmp1 = pow(10.0,N)/N;
    tmp2 = pow(9.0,pwr);
  }while(tmp1 <= tmp2);

  int MAX = pow(10, N);
  vector<int> nums;
  for(int i = 2; i != MAX; ++i)
    {
      stringstream ss;
      ss << i;
      string s = ss.str();

      double sum = 0;
      for(string::size_type j = 0; j != s.size(); ++j)
	sum += pow(strtod(s.substr(j,1).c_str(), NULL),pwr);
      
      if(i == sum)
	nums.push_back(i);
    }

  int result = 0;
  for(int i= 0; i != nums.size(); ++i)
    result += nums[i];

  cout << result << endl;

  return 0;
}
