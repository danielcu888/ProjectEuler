#include <iostream>
#include <iomanip>

using std::cout; using std::endl;
using std::setprecision;

int main()
{
  double n = 40, m = 20, sum = 1;
  for(long i = n; i > m; --i)
    {
      sum *= i/(i-m);
      cout << setprecision(15) << "sum = " << sum << endl;
    }

  return 0;
}
