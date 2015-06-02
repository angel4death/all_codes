#include<iostream>
using namespace std;
int n,m,b;
long long count,mod;
int *c;
void calc_cost(int,int,int); 
int main()
{
  count=0; 
  cin>>n>>m>>b>>mod;
  c=new int[n+1]();
  for(int i=1;i<=n;++i)
    cin>>c[i];
  calc_cost(m,1,0);
  cout<<count;
  return 0;
}
void calc_cost(int nol,int i,int cost)
{
  int d;
  if(i==n)
    {
      d=cost+(nol*c[i]);
      if(d<=b)
	count=(count+1)%mod;
      return;
    }
  else
    {
      for(int j=0;j<=nol;++j)
	{
	  
	  calc_cost(nol-j,i+1,cost+(j*c[i]));
         
	}
    }
}
