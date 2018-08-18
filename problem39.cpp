#include <iostream>
#include <cmath>
#include <vector>

using std::cout; using std::endl;
using std::pow; using std::sqrt;
using std::floor; using std::ceil;
using std::vector;

static const int p = 1000;

vector<int>::size_type max(const vector<int>& count)
{
  int mx = 0; 
  vector<int>::size_type j = 0;
  
  for(vector<int>::size_type i = 0; i != p+1; ++i)
    if(count[i] > mx) 
      {
	j = i;
	mx = count[j];
      }
  return j;
}

int main()
{
  vector<int> count(p+1, 0);
  
  for(int a = 1; a != p; ++a)
    for(int b = a+1; b != p; ++b)
      {
	double c = sqrt(pow((double)a, 2.0)+pow((double)b, 2.0));
	int q = a + b + (int)c;
	if(floor(c) == ceil(c) && q <= p)
	  ++count[q];
      }
  cout << "Result = " << max(count) << endl;
  return 0;
}
