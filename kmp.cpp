#include<iostream>
#include<string>

using namespace std;
int getnext(string tocmp ,int next[]);
int kmp(string storeit,string tocmp,int next[]);
int flag=0;
int main()
{
  string storeit;
  getline(cin,storeit);
  string tocmp;
  getline(cin,tocmp);
  int next[100];
  getnext(tocmp,next);
  kmp(storeit,tocmp,next);
  cout << flag << endl;
}
int kmp(string storeit,string tocmp,int next[])
{
 int slen=storeit.length();
 int tlen=tocmp.length();
 int j=-1;
for(int i=0;i< slen;i++)
{
  while(j>=0 && tocmp[j+1]!=storeit[i])
    j=next[j];
  if(tocmp[j+1]==storeit[i])
    j++;
  if(j==tlen-1)
    {
      flag++;
      j=-1;
    }
}
  return 0;

}
int getnext(string tocmp,int next[])
{
  int len=tocmp.length();
  next[0]=-1;
  int j=-1;
  for(int i=1;i<len;i++)
  {
    while(j>=0 && tocmp[i]!=tocmp[j+1])
      j=next[j];
    if(tocmp[i]==tocmp[j+1])
      j++;
    next[i]=j;
  
  }
  return 0;


}
