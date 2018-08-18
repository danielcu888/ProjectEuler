#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <string>
#include <fstream>

using std::find_if; using std::max;
using std::domain_error; using std::string;
using std::endl; using std::cout;
using std::vector; using std::ifstream;

bool is_letter(char c)
{
  return isalpha(c) ? true : false;
}

bool not_letter(char c)
{
  return !is_letter(c);
}

vector<string> words(const string& s)
{
  vector<string> v;
  string::const_iterator i = s.begin(), j;
  while(i != s.end())
    {
      i = find_if(i, s.end(), is_letter);
      j = find_if(i, s.end(), not_letter);
      if(i != j)
	v.push_back(string(i, j));
      i = j;
    }
  return v;
}

string::size_type max_size(const vector<string>& v)
{
  string::size_type m = 0;
  for(vector<string>::size_type i = 0; i != v.size(); ++i)
    m = max(m, v[i].size()); 
  return m;
}

vector<int> tri_nums(int max)
{
  int tmp = 1;
  vector<int>::size_type i = 1;
  vector<int> ret;
  while(tmp <= max * 26)
    {
      tmp = i*(1+i)/2;
      ret.push_back(tmp);
      ++i;
    }
  return ret;
}

int letter_val(char c)
{
 static const char alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

 int i = 0;
 while(c != alphabet[i] && i != 26)
   ++i;
 if(i == 26)
   throw domain_error("letter not found!");
 return i+1;
}

int word_val(const string& s)
{
  int val = 0;
  for(string::size_type i = 0; i != s.size(); ++i)
    val += letter_val(s[i]);
  return val;
}

bool is_tri_num(int n, vector<int> tris)
{
  bool ret = false;
  vector<int>::size_type i = 0;
  while(i != tris.size())
    {
      if(n == tris[i])
	return true;
      ++i;
    }
  return false;
}

int main()
{
  ifstream infile("./words.txt");
  string s;
  getline(infile, s);
  
  vector<string> wds = words(s);
  vector<int> tris = tri_nums(max_size(wds));
  
  int count = 0;
  for(vector<string>::size_type i = 0; i != wds.size(); ++i)
    count = is_tri_num(word_val(wds[i]), tris) ? count +1 : count;
    
  cout << count << endl;
  return 0;
}
