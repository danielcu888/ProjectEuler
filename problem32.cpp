/*
 * problem32.cpp
 *
 *  Created on: Nov 20, 2011
 *      Author: danielcumberbatch
 */
#include <iostream>
#include <vector>
#include <map>

using std::vector; using std::cout;
using std::endl; using std::map;

int num_digits(int num)
{
  int no_digits	= 0;
  while(num != 0)
    {
      num/=10;
      ++no_digits;
    }
  return no_digits;
}

bool digits_used(int num, vector<bool>& used)
{
  do {
    int val = num % 10;
    bool chk = used[val];
    if(val == 0 || chk)
      return false;
    used[val] = true;
    num /= 10;
  } while(num != 0);
  return true;
}

int main()
{
	static const int cmax = 9876;
	map<int, int> nums;

	for(int a = 1; a <= cmax; ++a)
	{
		int n_a = num_digits(a);
		for(int b = 1; b <= a; ++b)
		{
			vector<bool> used(10, false);
			if(!digits_used(a, used)) break; //checks for repeating digits and 0's in a, if so then iterate a
			int c = a*b;
			if(c > cmax) continue;
			if(n_a + num_digits(b) + num_digits(c) != 9) continue;
			if(!digits_used(b, used)) continue; //check for repeating digits and for 0's in a and b
			if(!digits_used(c, used)) continue; //check for repeating digits and 0's in a,b and c
			++nums[c];
		}
	}

	int sum = 0;
	for(map<int, int>::const_iterator i = nums.begin(); i != nums.end(); ++i)
		sum += i->first;
	cout << "result = " << sum << endl;

	return 0;
}

