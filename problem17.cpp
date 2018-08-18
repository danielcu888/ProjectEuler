#include <string>
#include <iostream>
#include <cmath>
#include <stdexcept>

using std::string; using std::cout;
using std::endl; using std::floor;
using std::domain_error;

static const string units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
static const string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
static const string decades[] = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
static const string hundred_and = "hundredand";
static const string one_thousand = "onethousand";
static const string hundred = "hundred";

int num_char(int n)
{
  int num = 0;

  if(n < 10)
    num = units[n].size();
  else if(n < 20)
    num = teens[n-10].size();
  else if(n < 100)
    {
      int numtens = floor(n/10);
      num = decades[numtens].size() + units[n-numtens*10].size();
    }
  else
    throw domain_error("n too large.");

  return num;
}

int main(int argc, char* argv[])
{
  int sum = 0;

  for(int n = 1; n != 1001; ++n)
    {
      int letters = 0;
      
      if(n < 100)
	letters = num_char(n);
      else if(n < 1000)
	{
	  int num_hundreds = floor(n/100);
	  
	  if(n - 100*num_hundreds == 0)
	    letters = units[num_hundreds].size() + hundred.size();
	  else
	    letters = units[num_hundreds].size() + hundred_and.size() + num_char(n-100*num_hundreds);
	}
      else if(n == 1000)
	letters = one_thousand.size();
      else
	throw std::domain_error("n too large");
      
      sum += letters;
    }
  
  cout << sum << endl;
  
  return 0;
}
