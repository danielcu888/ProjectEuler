#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>

using std::vector; using std::floor;
using std::cout; using std::endl;
using std::log10; using std::ifstream;
using std::string; using std::strtod;
using std::ostream; using std::floor;

vector<int>::size_type max_fill(const vector<int>& v)
{
  for(size_t i = v.size() - 1; i >= 0; --i)
    if(v[i] != 0) return floor(i + 1);
}

int main(int argc, char* argv[])
{
  if(argc != 2)
    {
      cout << "Usage: <program name> <input file>" << endl;
      return 0;
    }

  ifstream infile(argv[1]);
  vector<vector<int> > nums;
  string s;
  while(getline(infile, s))
    {
      vector<int> temp;
      for(string::size_type i = s.size(); i != 0; --i)
	temp.push_back(strtod(s.substr(i-1,1).c_str(), NULL));
      for(string::size_type i = s.size(); i != 100; ++i)
	temp.push_back(0);
      nums.push_back(temp);
    }
  
  vector<int> a = nums[0];
  vector<int>::size_type max;

  for(vector<vector<int> >::size_type p = 1; p != nums.size(); ++p)
    { 
      for(vector<int>::size_type i = 0; i != a.size()-2; ++i) //sort vector
	{
          if(a[i] >= 10)
            {
              do {
		a[i] -= 10;
                a[i+1] += 1;
              } while(a[i] >= 10);
            }
        }

      max = max_fill(a);
      for(vector<int>::size_type j = 0; j != max; ++j) //add elements
	a[j] += nums[p][j];
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
  
  max = max_fill(a);
  
  cout << "The first 10 digits of the sum are: ";
  for(size_t l = max; l != max-10; --l)
    cout << a[l-1];
  cout << endl;
  
  return 0;
}
