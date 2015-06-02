#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int count=0;
void find(string s)
{
  for(int i=0;i<s.length()/2;++i)
    {
      if(s[i]==s[s.length()-i-1])
	continue;
      else
	{
	  cout<<"NO";
          exit(0);
	}
    }
  count++;
  return;  
}
int main()
{
  string s;
  cin>>s;
  int k;
  cin>>k;
  if(s.length()%k!=0)
    {
      cout<<"NO";
      exit(0);
    }
  int len=s.length()/k;
  int i=0;
  while((i+len)<=s.length()) 
    { 
    find(s.substr(i,len));
    i+=len;
    }

  if(count==k)
    cout<<"YES";

  return 0;
}
