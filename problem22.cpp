#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstddef>

using std::ifstream; using std::endl;
using std::string; using std::cout;
using std::vector; using std::find_if;
using std::find; using std::sort;
using std::size_t;

size_t letter_value(char c)
{
  static const string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  return 1+letters.find(c);
}

bool is_valid_char(char c)
{
  static const string invalid_chars = "\",";
  return find(invalid_chars.begin(), invalid_chars.end(), c) == invalid_chars.end();
}

bool not_valid_char(char c)
{
  return !is_valid_char(c);
}

int main()
{
  ifstream infile("./names.txt");
  string s;
  getline(infile, s);
  
  vector<string> v;

  string::iterator i = s.begin(), j = s.begin();
  while(i != s.end())
    {
      i = find_if(i, s.end(), is_valid_char);
      j = find_if(i, s.end(), not_valid_char);
      
      if(i != j)
	v.push_back(string(i,j));
      
      i = j;
    }
  
  //sort vector
  sort(v.begin(), v.end());

  int sum = 0;

  for(vector<string>::size_type i = 0; i != v.size(); ++i)
    {
      int result = 0;
      for(string::size_type j = 0; j != v[i].size(); ++j)
	result += letter_value(v[i][j]);
      result *= i+1;
      sum += result;
    }

  cout << sum << endl;

  return 0;
}
