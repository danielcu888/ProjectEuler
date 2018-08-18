#include <cstdlib>
#include <cmath>
#include <iostream>

using std::sqrt;
using std::endl;
using std::cout;

inline bool is_pentagonal(int n)
{
  const double tmp = (sqrt(24.0*n + 1.0) + 1.0) / 6.0;
  return tmp == (int)tmp;
}

inline int pentagonal(int n)
{
  return n*(3*n - 1)/2;
}

int main(int argc, char* argv[])
{
  
  bool found = false;
  int i = 0;
  int j = 0;
  int P_i = 0.;
  int P_j = 0.;
  int result = 0;
  
  while(!found)
    {
      ++i;
      P_i = pentagonal(i);
      for (j = i - 1; !found && j > 0; --j)
	{
	  P_j = pentagonal(j);
	  found = is_pentagonal(P_i+P_j) &&
	    is_pentagonal(P_i-P_j);
	  if (found) result = P_i - P_j;
	}
    }

  cout << "i = " << i
       << ", P_i = " << P_i
       << ", j = " << j
       << ", P_j = " << P_j 
       << ", result = " << result 
       << endl;
  
  return EXIT_SUCCESS;
}
