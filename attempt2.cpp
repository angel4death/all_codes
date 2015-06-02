#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
char num[1<<5][1<<5][6];
vector<int> v[6];
int res_mask[21],ccount[6],A[6],B[21],N,M,found=0;
int res_col[21][6];
int get[1<<5][1<<5];
int pre[21][11][11][11][11][11];
void precompute(int N)
{
  int k=(1<<N);
  for(int i=0;i<k;++i)
    for(int j=0;j<k;++j)
      get[i][j]=(i/(1<<j))%2;
  for(int i=0;i<k;++i)
    for(int j=0;j<k;++j)
      for(int p=0;p<N;++p)
    if((i&(1<<p))==0 && (j&(1<<p))!=0)
      num[i][j][p]=1;
    else
      num[i][j][p]=0;
  int temp=0,flag=0,cc=0;
  for(int i=0;i<k;++i)
    {
      temp=i;
      flag=0;
      cc=0;
      while(temp)
    {
      if(temp&1 == 1)
            {
        if(!flag)
          {
        cc++;
        flag=1;
          }
        }
        else
          flag=0;
      temp>>=1;
    }
      v[cc].push_back(i);
    }
}   
int isvalid(int p,int value)
{
  int is_valid=1;
  
  for(int i=0;i<N;++i)
    {
      ccount[i]=res_col[p][i]+num[res_mask[p]][value][i];
      if(ccount[i]>A[i+1])
    {
      is_valid=0;
      break;
    }
    }
  if(is_valid)
    {
      if(p==M-1)
    {
      for(int i=0;i<N;++i)
        {
          if(ccount[i]!=A[i+1])
        {
          is_valid=0;
          break;
        }
        }
      if(is_valid) 
        found=1;
    }
    }
  return is_valid;
}
void print_the_answer(int ans[6])
{
  
  for(int i=0;i<N;++i)
    {
      for(int j=1;j<=M;++j)
    {
      if(get[ans[j]][i]==1)
         cout<<"*";
      else
        cout<<".";
    }
      cout<<endl;
    }
  exit(0);
} 


void dfs(int k)
{
  int size=v[B[k]].size();
  for(int i=0;i<size;++i)
    {
      int t=isvalid(k-1,v[B[k]][i]);
      if(t)
    {
      res_mask[k]=v[B[k]][i];
      for(int p=0;p<6;++p)
        res_col[k][p]=ccount[p];
          if(pre[k][ccount[0]][ccount[1]][ccount[2]][ccount[3]][ccount[4]]==-1)
            continue;
             dfs(k+1);
            if(found==1)
            {
               print_the_answer(res_mask);
               return ;
               }
            else
          {
        pre[k][res_col[k][0]][res_col[k][1]][res_col[k][2]][res_col[k][3]][res_col[k][4]]=-1;
          continue;
          }
    }
    
  }
  return;
}
int main()
{
  cin>>N>>M;
  for(int i=1;i<=N;++i)
    cin>>A[i];
  for(int i=1;i<=M;++i)
    cin>>B[i];
          
  for(int i=0;i<6;++i)
    res_col[0][i]=0;
  precompute(N);
  dfs(1);
  return 0;
}
