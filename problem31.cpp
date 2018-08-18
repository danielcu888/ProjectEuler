#include <iostream>

using std::cout;
using std::endl;

int main()
{
  int num_coms = 1;

  for(int a = 0; a <= 2; a++)
    for(int b = 0; b <= 4; b++)
      for(int c = 0; c <= 10; c++)
	for(int d = 0; d <= 20; d++)
	  for(int e = 0; e <= 40; e++)
	    for(int f = 0; f <= 100; f++)
	      if((a*100 + b*50 + c*20 + d*10 + e*5 + f*2) <= 200) ++num_coms;

  cout << num_coms << endl;

  return 0;
}
