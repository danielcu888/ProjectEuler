#include <iostream>
#include <iomanip>

using std::cout; using std::endl;
using std::setprecision;

int main()
{
  double fixed = 100.0*101.0/2.0;
  double sum = 0;

  for(int i = 1; i != 101; ++i)
    {
      sum += i*(fixed - i);
    }

  cout << setprecision(10) << sum << endl;


  return 0;
}
