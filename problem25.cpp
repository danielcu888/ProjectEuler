#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <string>
#include <stdexcept>

using std::vector; using std::floor;
using std::cout; using std::endl;
using std::log10; using std::stringstream;
using std::string; using std::strtod;
using std::pow;

vector<long>::size_type max_fill(const vector<long>& v)
{
  for(size_t i = v.size() - 1; i >= 0; --i)
    if(v[i] != 0) return floor(i + 1);
}

void display(const vector<long>& v)
{
  for(vector<long>::size_type i = 0; i != v.size(); ++i)
    cout << v[i] << " ";
  cout << endl;
}

int main()
{
  const vector<long>::size_type MAX_DIG = 1000;
  const vector<long>::size_type x = 2000;

  vector<long> a(x,0), b(x,0);
  a[0] = 1;
  b[0] = 1;

  vector<long>::size_type max = 1;

  size_t p = 2;

  while(max < MAX_DIG)
    {
      //cout << "br1: "; display(a); cout << "     "; display(b);
      for(vector<long>::size_type j = 0; j != max; ++j) //construct p+1 th term of sequence
	{
	  long store = a[j];
	  a[j] += b[j];
	  b[j] = store;
	}
      //cout << "br2: "; display(a); cout << "     "; display(b);

      for(vector<long>::size_type i = 0; i != x-2; ++i) //sorts vectors
	{
          while(a[i] >= 10)
            {
              int numzeros = floor(log10(a[i]));
              a[i] -= pow(10.0, numzeros);
	      //cout << "br3: "; display(a); cout << "     "; display(b);
              a[i+1] += pow(10.0, numzeros-1);
	      //cout << "br4: "; display(a); cout << "     "; display(b);
            }

          while(b[i] >= 10)
            {
              int numzeros = floor(log10(b[i]));
              b[i] -= pow(10.0, numzeros);
	      //cout << "br5: "; display(a); cout << "     "; display(b);
              b[i+1] += pow(10.0, numzeros-1);
	      //cout << "br6: "; display(a); cout << "     "; display(b);
            }
        }

      max = max_fill(a); //reset max fill, a must be larger than or of equal size to b 
      ++p; //increment term counter
      //cout << "p = " << p << endl;
    }

  cout << "F_" << p << " is the first term of the Fibonacci sequence to contain " 
       << MAX_DIG << " digits." << endl;

  return 0;
}
