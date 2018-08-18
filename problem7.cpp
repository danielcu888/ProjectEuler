#include <iostream>

using std::cout; using std::endl;

int main()
{
  long i = 3L;
  int count = 1;

  do
    {      
      long j = 1L;
      do {
	j+=2;
      }
      while(i % j != 0 && j <= i);
      
      if(j == i)
	{
	  ++count;
	  cout << count << " " << i << endl;
	}

      i += 2;

    } while(count < 10001);
  


  return 0;
}
