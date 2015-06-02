#include<iostream>
#include<string>

using namespace std;
int main()
{
  string s;
  cin>>s;
  int l=s.length();
  for(int i=0;i<(1<<l);++i)
    {
      cout<<"{";
      for(int j=0;j<l;++j)
        {
	  if(i & (1<<j))
	    cout<<s[j];
	}
      cout<<"}"; 
      cout<<endl;
    }
}  
