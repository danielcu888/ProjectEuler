#include <iostream>

using std::endl; using std::cout;
using std::cin;

bool is_factor(double n, double f)
{
  do{ 
    n -= f;
  }
  while(n > 0);
  return n == 0 ? true : false;
}

int main()
{
  int n, f;
  cout << "Enter integer: ";
  cin >> n;
  cout << "Enter factor: ";
  cin >> f;
  cout << "Factor? " << is_factor(n,f) << endl;
 
  return 0;
}
