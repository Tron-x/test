#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<map>
#include<unordered_map>
#include<istream>
#include<sstream>
using namespace std;
vector<string> split(string str,char delimiter)
{
  vector <string> internal;
  stringstream ss(str);
  string tok;
  while(getline(ss, tok ,delimiter))
  {
    internal.push_back(tok);
  }
  return internal;
}

bool wordPattern(string pattern, string str)
{
  unordered_map<char,string> dict_pattern;
  unordered_map<string,char> dict_string;
  int len=pattern.size();
  vector<string> strs=split(str,' ');
  if(len !=strs.size()) return false;
  for(int i=0; i<len;i++)
  {
    char& ch = pattern[i];
    string& s=strs[i];
    if(dict_pattern.find(ch) == dict_pattern.end())
    {
      dict_pattern[ch]=s;

    }
    if(dict_string.find(s)==dict_string.end())
    {
      dict_string[s]=ch;
    }
    if(dict_pattern[ch] !=s || dict_string[s] !=ch)
    {
      return false;
    }



  }
  return true;
}
int main()
{
  string pattern;
  cout<<"please input pattern:";
  getline(cin,pattern);
  string str;
  cout<<"please input string: ";
  getline(cin,str);
  bool wordp;
  wordp=wordPattern(pattern,str);
  cout<< wordp <<endl;
}
