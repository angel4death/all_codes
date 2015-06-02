#include<iostream>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;
vector<int> v[1004];
int color[1004],parent[1004],dd[1004],used[1004];
int bfs();
int stack[1004],top=0,tt,st[1004];
void dfs(int ver)
{
  st[++tt]=ver;
  used[ver]=1;
  for(vector<int>::iterator i=v[ver].begin();i!=v[ver].end();++i)
    if(used[*i]==1)
      continue;
    else
      dfs(*i);
}
int main()
{  
  int n,m,diameter=0,res;
  cin>>n>>m;
  memset(dd,0xF,sizeof(dd));
  int temp[1004];

  for(int i=1;i<=m;++i)
    {
      int a,b;
      cin>>a>>b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
  for(int i=1;i<=n;++i)
    {
     if(v[i].size()==0)
       continue;
     tt=-1;
     if(!used[i])
       {
	 res=0;
         dfs(i);
     for(int j=0;j<=tt;++j)
       {
         top=0;
         color[st[j]]=1;
         stack[++top]=st[j];
         dd[st[j]]=0;           
         res=max(res,bfs());
         memset(parent,0x0,sizeof(parent));
         memset(dd,0xF,sizeof(dd));
         memset(color,0x0,sizeof(color));
        }
     diameter+=res;
       }
     
    }
  cout<<diameter;
  return 0;
}
int bfs()
{
  int diameter=0;
  int start=1;
  for(int i=start;i<=top;++i)
    {
      for(vector<int>::iterator j=v[stack[i]].begin();j!=v[stack[i]].end();++j)
	{
	  if(parent[stack[i]]==*j)
	    continue;  
	  else
	    {
	      parent[*j]=stack[i];
	      if(color[*j]!=0)
		{
		  if(color[stack[i]]==color[*j])
		    {
		      cout<<-1;
		      exit(0);
		    }
		  else
		    {
		      dd[*j]=min(dd[*j],dd[stack[i]]+1);
                      diameter=max(diameter,dd[*j]);
		      continue;
		    }
		}
	      else
                {
                 if(color[stack[i]]==1)
                  color[*j]=2;
                 else
                  color[*j]=1;
                 dd[*j]=min(dd[*j],dd[stack[i]]+1);
                 diameter=max(diameter,dd[*j]);
                 stack[++top]=*j;
              }
        }
    }
      start++;
  }
  
  return diameter; 
}       
  

