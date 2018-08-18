/*
 * problem50.cpp
 *
 *  Created on: Nov 18, 2011
 *      Author: danielcumberbatch
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstddef>

using std::vector; using std::cout;
using std::endl; using std::size_t;

static const long MAX = 1000000;

vector<long> primes()
{
  vector<long> a(MAX, 1);
  a[0] = 0; a[1] = 0;
  for(long i = 2L; i != MAX; ++i)
    for(long j = 2L; j*i < MAX; ++j)
      a[j*i] = 0;
  return a;
}

static const vector<long> a = primes();

bool is_prime(long n)
{
  return a[n] == 1;
}

int main(int argc, char* argv[])
{
  typedef vector<long>::size_type vec_sz;

  vector<long> b;
  for(vec_sz i = 0; i != a.size(); ++i)
    if(is_prime(i))
      b.push_back(i);

  vector<long> c;
  for(vec_sz i = 0; i != b.size(); ++i)
    {
      long tmp = 0L;
      for(vec_sz j = 0; j <= i; ++j)
	tmp += b[j];
      c.push_back(tmp);
    }

  long result = 0L;
  vec_sz max_nums = 0;

  for(vec_sz start = 0; start < c.size(); ++start)
    for(vec_sz end = start; end < c.size(); ++end)
      {
	long sum = c[end] - c[start];
	if(sum < MAX && (end - start) > max_nums && is_prime(sum))
	  {
	    max_nums = end - start;
	    result = sum;
	  }
      }

  cout << result << endl;
  return 0;
}
