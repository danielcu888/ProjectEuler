/*
 * problem38.cpp
 *
 *  Created on: Nov 21, 2011
 *      Author: danielcumberbatch
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using std::vector; using std::cout;
using std::endl; using std::max;
using std::string;

static int MAX = 100000;

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

int form_pandigital(int x, int max_mult)
{
	string s;
	for(int i = 0; i != max_mult; ++i)
	{
		string tmp;
		int n = i*x;
		while(n != 0)
		{
			char c = (n % 10) + 48;
			tmp += c;
			n /= 10;
		}

		for(string::const_reverse_iterator j = tmp.rbegin();
				j != tmp.rend(); ++j)
			s += *j;
	}

	int ret = 0;
	for(string::size_type i = 0; i != s.size(); ++i)
	{
		ret *= 10L;
		ret += static_cast<int>(s[i]) - 48L;
	}
	return ret;
}

int main()
{
	int max_num = 0;
	for(int x = 1; x != MAX; ++x)
	{
		vector<bool> used(10, false);
		int digs = 0, mult = 1;

		while(digits_used(mult*x, used))
		{
			digs += num_digits(mult*x);
			++mult;
		}
		if(digs != 9) continue;
		max_num = max(max_num, form_pandigital(x, mult));
	}
	cout << max_num << endl;
	return 0;
}
