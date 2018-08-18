#include <iostream>

using std::cout; using std::endl;

int main()
{
  for(int a = 998; a != 1; --a)
    {
      for(int b = 998; b >= a; --b)
        { 
          for(int c = 998; c >= b; --c)
            {
              if(a + b + c == 1000)
		{ 
		  if((a * a) + (b * b) == (c * c))
                    {
		      cout << "a = " << a << " "
			   << "b = " << b << " "
			   << "c = " << c << endl;
		      cout << "a*b*c = " << a*b*c << endl;
		    }
                }
	      
            }
        }
    }
  
  return 0;
}
