#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
vector<int> hs[1000000];
int order[1000000];
int stop,nohs,n;
int  main()
{
  int noh;
  cin>>n;
  for(int i=1;i<=n;++i)
    {
      cin>>noh;
      hs[noh].push_back(i);
    }
  noh=0;
  vector<int>::iterator v;
  while(noh>=0)
    {
      if(hs[noh].empty())
	 {
	   noh-=3;
	 }
	 else
	   {
	     v=hs[noh].end();
	     v--;
	     order[stop++]=*v;
	     hs[noh].pop_back();
	     noh++;
	   }
    }
  if(stop==n)
    {
      cout<<"POSSIBLE"<<endl;      
      for(int i=0;i<stop;++i)
	cout<<order[i]<<" ";
    }
  else
    cout<<"IMPOSSIBLE"; 
  return 0;
}



	 













