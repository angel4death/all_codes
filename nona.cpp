#include<iostream>
#include<stdlib.h>
using namespace std;
int res_mask[6],res_col[6][21],get[1<<21][21],r,c,*row,*col,found=0,ccount[21];
void pre_get()
{
  for(int i=0;i<(1<<21);++i)
    for(int j=0;j<21;++j)
      get[i][j]=(i/(1<<j))%2;
}
void print_the_answer(int ans[6])
{
  
  for(int i=0;i<r;++i)
    {
      for(int j=0;j<c;++j)
	{
	  if(get[ans[i]][j]==1)
	     cout<<"*";
	  else
	    cout<<".";
	}
      cout<<endl;
    }
  exit(0);
}
int ismaskvalid(int ind,int mask)
{
  static int counter;
  cout<<counter++<<" ";
  int  isvalid=1;
  int rcount=0;
   for(int i=0;i<c;++i)
    {
      if(get[mask][i]==1)
	if(i==0)
	  rcount=1;
	else
	  if(get[mask][i-1]==0)
	    rcount+=1;
    }
  if(rcount!=row[ind])
    isvalid=0;
  if(isvalid)
    {
      if(ind==0)
	for(int i=0;i<c;++i)
	  {
	    if(get[mask][i]==1)
	      ccount[i]=1;
            else ccount[i]=0; 
	    if(ccount[i]>col[i]){ isvalid=0;break;}
	  }
      else
	for(int i=0;i<c;++i)
	  {
	    ccount[i]=res_col[ind-1][i];
	    if(get[mask][i]==1)
	      {
		if(get[res_mask[ind-1]][i]==0)
		  ccount[i]+=1;
	      }
	    if(ccount[i]>col[i]){isvalid=0;break;}
	  }
      if(isvalid)
	if(ind==r-1)
	  {
	    for(int i=0;i<c;++i)
	      {
		if(ccount[i]!=col[i]){isvalid=0;break;}
	      }
	    if(isvalid)
	      found=1;
	  }
    }
  return isvalid;
}
void calculate(int ind)
{
  for(int i=0;i<(1<<c);++i)
    {
      int t=ismaskvalid(ind,i);
      if(t)
	{
	  res_mask[ind]=i;
	  for(int p=0;p<c;++p)
	  res_col[ind][p]=ccount[p];
	  calculate(ind+1);
	  if(found==1)
	    print_the_answer(res_mask);
	  else
	    continue;
	}
    }
  return;
}

int main()
{
  cin>>r>>c;
  row=new int[r]();
  col=new int[c]();
  for(int i=0;i<r;++i)
    cin>>row[i];
  for(int i=0;i<c;++i)
    cin>>col[i];
  pre_get();
  calculate(0);
  return 0;
}




