#include<iostream>
#include<vector>
#include<string>
using namespace std;
string convert(string s,int nrows)
{
  vector<string> r(nrows);
  int row=0;
  int step=1;
  for(int i=0;i<s.size();i++)
  {
    if(row==nrows-1) step=-1;
    if(row==0) step=1;
    r[row]+=s[i];
    row+=step;
  }
  string result;
  for(int i=0;i<nrows;i++)
  {
    result+=r[i];
  }
  return result;

}
int main()
{
  string s;
  int r;
  s="PAYPALISHIRING";
  r=3;
  cout<<s<<":"<<convert(s,3) << endl;
  return 0; 


}
