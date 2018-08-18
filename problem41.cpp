#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>

using std::pow; using std::floor; using std::ceil;
using std::string; using std::stringstream;
using std::out_of_range; using std::cout; using std::endl;
using std::prev_permutation;

bool is_prime(int num)
{
	for(int i = 2; i <= pow((double)num, 0.5); ++i)
		{
			double tmp = (double)num / (double)i;
			if(floor(tmp) == ceil(tmp))
				return false;
		}
	return true;
}

bool is_pandigital(int num)
{
	string digits = "0123456789";
	bool used[10];
	for(size_t i = 0; i != 10; ++i) used[i] = false;
	stringstream ss;
	ss << num;
	string s = ss.str();
	for(size_t i = 0; i != s.size(); ++i)
	{
		size_t idx = 0;
		while(idx < digits.size() && s[i] != digits[idx]) ++idx;
		if(idx < digits.size())
		{
			if(idx == 0) return false; //numbers containing 0 cannot be pandigital
			if(used[idx]) return false; //numbers with two or more occurrences of same digit are not pandigital
			used[idx] = true; //indicate presence of current digit
		}
		else
			throw out_of_range("Digit not found!");
	}

	size_t n = 1;
	while(n < 10 && used[n]) ++n;
	return s.size() == n-1 ? true : false;
}

int construct_num(int* beg, size_t length, size_t max_length)
{
	int ret = 0;
	for(size_t i = 0; i != length; ++i)
		ret += ((int)pow(10.0, (double)i))*beg[max_length-1-i];
	return ret;
}

int main()
{
	static const int a[] = {9,8,7,6,5,4,3,2,1};
	static const size_t MAX_LENGTH = 9;

	int b[MAX_LENGTH];
	for(int j = 9; j != 0; --j)
	{
		for(size_t i = 0; i != MAX_LENGTH; ++i) b[i] = a[i]; //reset b
		do {
			int i = construct_num(b, j, MAX_LENGTH);
			//cout << i << endl;
			if(is_pandigital(i) && is_prime(i))
			{
				cout << i << " is both pandigital and prime." << endl;
				return i;
			}
		} while(prev_permutation(b+MAX_LENGTH-j, b+MAX_LENGTH));
		cout << "no " << j << " digit pandigital prime numbers exist." << endl;
	}

	return 0;
}

