#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>

using std::ifstream; using std::vector;
using std::string; using std::isspace;
using std::cout; using std::endl;
using std::istream; using std::ostream;
using std::copy; using std::back_inserter;

bool space(char c)
{
  return isspace(c);
}

bool not_space(char c)
{
  return !isspace(c);
}

vector<vector<int> > construct(istream& in)
{
  vector<vector<int> > ret1, ret2;
  string s;

  while(getline(in, s))
    {
      vector<int> v;
      string::iterator i = s.begin(), j;

      while(i != s.end())
        {
          i = find_if(i, s.end(), not_space);
          j = find_if(i, s.end(), space);

          if(i != j)
            v.push_back(atoi(string(i,j).c_str()));
          i = j;
        }
      ret1.push_back(v);
    }

  copy(ret1.rbegin(), ret1.rend(), back_inserter(ret2));
    
  return ret2;
}

ostream& display(ostream& os, const vector<vector<int> >& tri)
{
  for(vector<vector<int> >::size_type i= 0; i != tri.size(); ++i)
    {
      for(vector<int>::size_type j = 0;j != tri[i].size(); ++j)
	cout << tri[i][j] << " ";
      cout << endl;
    }
  return os;
}

vector<long> lengths(const vector<vector<int> >& tri)
{
  vector<int>::size_type base = tri[0].size();
  long l = 1;
  vector<long> lengths;
  for(vector<vector<int> >::size_type i = 0; i != tri.size()-1; ++i)
    {
      l *= tri[i].size();
      lengths.push_back(l);
      //cout << lengths[i] << endl;
    }
  return lengths;
}

vector<long> num(const vector<vector<int> >& tri, long n)
{
  vector<long> ret(tri.size(), 0);
  vector<long> l = lengths(tri);
  vector<int>::size_type i = 0;
  while(n > l[i])
    ++i;

  for(vector<vector<int> >::size_type j = i; j != 0; --j)
    {
      while(n > l[i-1])
	{
	  n -= l[i-1];
	  ++ret[i];
	}
      ret[i-1] = n;
    }

  return ret;
}

int main()
{
  ifstream infile("triangle.txt");
  vector<vector<int> > tri = construct(infile);
  //display(cout, tri);
  
  vector<long> ret = num(tri, 230);
  for(vector<long>::size_type i = 0; i != ret.size(); ++i)
    cout << ret[i] << " ";
  cout << endl;

  return 0;
}
