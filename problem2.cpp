#include <iostream>

using std::cout; using std::endl;

int main()
{
  int prev = 0, next = 1, nextnext, sum;

  do
    {
      nextnext = prev + next;
      prev = next;
      next = nextnext;
      if(nextnext % 2 == 0)
	sum += nextnext;
    }
  while(nextnext < 4000000);

  cout << "sum: " << sum << endl;

  return 0;
}
