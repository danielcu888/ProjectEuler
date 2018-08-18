#include <vector>
#include <iostream>

using std::vector; using std::cout;
using std::endl;

static const int N = 1000000-1;

int main()
{
  vector<int> result;
  vector<int> num_avail(1,0);
  vector<int> factorials(1,1);
  for(int i = 1; i != 10; ++i)
    {
      num_avail.push_back(i);
      int tmp = 1;
      int j = i;
      while(j >= 1)
	{
	  tmp *= j;
	  --j;
	}
      factorials.push_back(tmp);
    }
  
  int remainder = N;

  while(num_avail.size() > 1)
    {
      vector<int>::iterator it = num_avail.begin();
      while(remainder >= factorials[num_avail.size()-1])
	{
	  remainder -= factorials[num_avail.size()-1];
	  ++it;
	}
      
      result.push_back(*it);
      num_avail.erase(it);

      for(vector<int>::size_type i = 0; i != result.size(); ++i)
	cout << result[i] << "";
      cout << endl;
    }

  result.push_back(num_avail[0]);

  for(vector<int>::size_type i= 0; i != result.size(); ++i)
    cout <<result[i] << "";
  cout << endl;

  return 0;
}
