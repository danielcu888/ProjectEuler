#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

using std::ifstream; using std::cout;
using std::strtod; using std::endl;
using std::vector; using std::string;
using std::ostream; using std::max;
using std::min; using std::domain_error;

static const size_t num_adj = 4;

vector<vector<int> > init(const char* filename)
{
  vector<vector<int> > ret;

  ifstream infile(filename);

  string s;
  while(getline(infile, s))
    {
      vector<int> v;
      string::size_type i = 0;
      while(i < s.size())
	{
	  int num1 = strtod(s.substr(i,1).c_str(), NULL);
	  int num2 = strtod(s.substr(i+1,1).c_str(), NULL);

	  if(num1 != 0)
	    v.push_back(strtod(s.substr(i,2).c_str(), NULL));
	  else
	    v.push_back(strtod(s.substr(i+1,1).c_str(), NULL));
	  i += 3;
	}
      ret.push_back(v);
    }
  return ret;
}

int left(size_t row, size_t col, int prod, const vector<vector<int> >& v)
{
  int temp = 1;
  size_t i = row, j = col;
  int count = 0;
  do {
    temp *= v[i][j--];
    ++count;
  } while(count != num_adj);
  return max(prod, temp);
}

int left_upper(size_t row, size_t col, int prod, const vector<vector<int> >& v)
{
  int temp = 1;
  size_t i = row, j = col;
  int count = 0;
  do {
    temp *= v[i--][j--];
    ++count;
  } while(count != num_adj);
  return max(prod, temp);  
}

int up(size_t row, size_t col, int prod, const vector<vector<int> >& v)
{
  int temp = 1;
  size_t i = row, j = col;
  int count = 0;
  do {
    temp *= v[i--][j];
    ++count;
  } while(count != num_adj);
  return max(prod, temp);
}

int right_upper(size_t row, size_t col, int prod, const vector<vector<int> >& v)
{
  int temp = 1;
  size_t i = row, j = col;
  int count = 0;
  do {
    temp *= v[i--][j++];
    ++count;
  } while(count != num_adj);
  return max(prod, temp);
}

int right(size_t row, size_t col, int prod, const vector<vector<int> >& v)
{
  int temp = 1;
  size_t i = row, j = col;
  int count = 0;
  do {
    temp *= v[i][j++];
    ++count;
  } while(count != num_adj);
  return max(prod, temp);
}

int right_lower(size_t row, size_t col, int prod, const vector<vector<int> >& v)
{
  int temp = 1;
  size_t i = row, j = col;
  int count = 0;
  do {
    temp *= v[i++][j++];
    ++count;
  } while(count != num_adj);
  return max(prod, temp);
}

int down(size_t row, size_t col, int prod, const vector<vector<int> >& v)
{
  int temp = 1;
  size_t i = row, j = col;
  int count = 0;
  do {
    temp *= v[i++][j];
    ++count;
  } while(count != num_adj);
  return max(prod, temp);
}

int left_lower(size_t row, size_t col, int prod, const vector<vector<int> >& v)
{
  int temp = 1;
  size_t i = row, j = col;
  int count = 0;
  do {
    temp *= v[i++][j--];
    ++count;
  } while(count != num_adj);
  return max(prod, temp);
}

int height(const vector<vector<int> >& v)
{
  return v.size();
}

int max_wd(const vector<vector<int> >& v)
{
  size_t ret = 0;
  for(size_t i = 0; i != v.size(); ++i)
    ret = max(ret, v[i].size());
  return ret;
}

int min_wd(const vector<vector<int> >& v)
{
  size_t ret = 0;
  for(size_t i = 0; i != v.size(); ++i)
    ret = min(ret, v[i].size());
  return ret;
}

int main(int argc, char* argv[])
{
  if(argc != 2)
    {
      cout << "Usage: <program name> <input filename>" << endl;
      return 0;
    }
  vector<vector<int> > nums = init(argv[1]);
  
  int ht = height(nums);
  if(ht == 0)
    throw domain_error("Empty grid!");
  
  if(min_wd(nums) != max_wd(nums) && max_wd(nums) != ht)
    throw domain_error("Invalid grid configuration.");
  int wd = ht;

  int prod = 0;

  for(size_t i = 0; i != ht; ++i)
    {
      for(size_t j = 0; j != wd; ++j)
	{
	  if(j >= num_adj-1)
	    {
	      prod = left(i,j,prod,nums);
	      if(i >= num_adj-1)
		{
		  prod = left_upper(i,j,prod,nums);
		  prod = up(i,j,prod,nums);
		}
	      if(i <= (ht-1)-(num_adj-1))
		{
		  prod = left_lower(i,j,prod,nums);
		  prod = down(i,j,prod,nums);
		}
	    }
	  if(j <= (wd-1)-(num_adj-1))
	    {
	      prod = right(i,j,prod,nums);
	      if(i >= num_adj-1)
		{
		  prod = right_upper(i,j,prod,nums);
		  prod = up(i,j,prod,nums);
		}
	      if(i <= (ht-1)-(num_adj-1))
		{
		  prod = right_lower(i,j,prod,nums);
		  prod = down(i,j,prod,nums);
		}
	    }
	}
    }

  cout << "The greatest product of " << num_adj << " adjacent numbers on the "
       << "same straight line in your " << ht << "-by-" << wd << " grid is: "
       << prod << endl;

  return 0;
}
