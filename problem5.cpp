#include <iostream>

using std::cout; using std::endl;

int main()
{
  long i = 20L;
  for(i; ; i += 20)
    {
      if(i % 19 != 0) continue;
      if(i % 18 != 0) continue;
      if(i % 17 != 0) continue;
      if(i % 16 != 0) continue;
      if(i % 15 != 0) continue;
      if(i % 14 != 0) continue;
      if(i % 13 != 0) continue;
      if(i % 12 != 0) continue;
      if(i % 11 != 0) continue;
      break;
    }

  cout << i << endl;


  return 0;
}
