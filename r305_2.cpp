#include<iostream>
using namespace std;
int main()
{
  int n,m,max_count[500],ans[500],count,row,col,q,temp;
  cin>>n>>m>>q;
  int arr[500][500];

  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
       cin>>arr[i][j];
      
  int t=-1;
  for(int i=0;i<q;++i)
    {
      int mm=0;
      count=0;  
      cin>>row>>col;
      arr[row-1][col-1]=arr[row-1][col-1]^1;
      for(int j=0;j<m;++j)
       {
         if(arr[row-1][j]==0)
	 {
	   if(count>=mm)
             {
	     mm=count;
             }
         count=0;	 
	 }
       else
	 {
	  count++;
	 }
      }
      if(count>mm)
	mm=count;
      max_count[row-1]=mm;
      int max=0;
      for(int k=0;k<row;++k)
	if(max_count[k]>max)
	  max=max_count[k];
      ans[++t]=max;     
    }
  for(int i=0;i<=t;++i)
    cout<<ans[t]<<endl;
  return 0;
}

