#include <vector>
#include <iostream>

using std::vector; using std::endl;
using std::cout;

long even(long n)
{
  return n/2;
}

long odd(long n)
{
  return 3*n + 1;
}

bool unused(long n, vector<int>::size_type start, const vector<int>& v)
{
  if(n > start || v[n] == 0) 
    return true;
  return false;
}

int max_val(const vector<int>& v)
{
  int max_count = 0;
  vector<int>::size_type j = 0;

  for(vector<int>::size_type i = 0; i != v.size(); ++i)
    {
      if(v[i] > max_count)
	{
	  max_count = v[i];
	  j = i;
	}
    }

  cout << "Max count is: " << max_count << ", occuring at i = " << j << endl;
  return max_count;
}

int main()
{
  const int START = 3;
  const int END = 1000000;
  int count = 0, max_count = 0;
  long n;
  vector<int> nums(END, 0);
  nums[1] = 1;

  for(int start = START; start < END; start += 2)
    {
      //cout << "start = " << start << endl;
      n = start;
      count = 0;

      do
	{
	  ++count;
	  
	  if(n % 2 == 0)
	    //    {
	      n = even(n);
	  //cout << "n = " << n << endl;
	  //}
	  else
	    //{
	      n = odd(n);
	  //cout << "n = " << n << endl;
	  //}	  
	}
      while(n > 1 && unused(n, start, nums));
      
      nums[start] = count + nums[n];
      //cout << "nums[start] = " << count << " + " << nums[n] 
      //	   << " = " << nums[start] << endl;
    }

  max_count = max_val(nums);

  return 0;
}
