#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <cstdio>
#include <cstdlib>

using std::vector; using std::out_of_range;
using std::stringstream; using std::cout;
using std::endl; using std::strtol;
using std::string;

static const long N = 2000000;

vector<long> primes()
{
  vector<long> ret(N, 1L);
  for(long i = 2L; i < N; ++i)
    if(ret[i] == 1L)
      for(long j = 2L; i*j < N; ++j)
	ret[i*j] = 0L;
  ret[0] = 0L;
  ret[1] = 0L;
  return ret;
}

bool is_prime(long l, const vector<long>& prime_nums)
{
  if(l >= N)
    throw out_of_range("is_prime: argument out of range");
  return prime_nums[l] == 1 ? true : false; 
}

vector<long> generate_nums(long l)
{
  stringstream ss;
  ss << l;
  string s = ss.str();
  vector<string> strs;
  for(string::size_type i = 0; i != s.size(); ++i)
    strs.push_back(s.substr(0,s.size() - i));
  if(s.size() > 1)
    for(string::size_type i = 1; i != s.size(); ++i)
      strs.push_back(s.substr(i, s.size()));
  vector<long> nums;
  for(vector<string>::size_type i = 0; i != strs.size(); ++i)
    nums.push_back(strtol(strs[i].c_str(), NULL, 0));
  return nums;
}

bool truncatable_prime(long l, const vector<long>& prime_nums)
{
  vector<long> nums = generate_nums(l);
  for(vector<long>::size_type i = 0; i != nums.size(); ++i)
    if(!is_prime(nums[i], prime_nums)) 
      return false;
  return true;
}

int main()
{
  long sum = 0;
  vector<long> prime_nums = primes(); 
  for(vector<long>::size_type i = 8; i != N; ++i)
    if(is_prime(i, prime_nums) && truncatable_prime(i, prime_nums))
      sum += i;
  cout << "Result = " << sum << endl;
  return 0;
}
