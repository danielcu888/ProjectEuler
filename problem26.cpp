#include <iostream>
#include <iomanip>
#include <ios>
using std::cout; using std::endl;
using std::setprecision;

int main()
{
  double d = 1000000.0*1000000.0*1.0/7.0;

  cout << setprecision(1000) << d << endl;
  return 0;
}
