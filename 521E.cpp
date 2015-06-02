#include<iostream>
#include<vector>
#include<stdlib.h>
#define fr(a,b) for(int i=a;i<b;++i)
using namespace std;
static int timer=0;
int top=-1,ctop=-1;
int visited[10000];
vector<int> parent[10000];
vector<int> v[10000];
pair<int,int> com[10000];
pair<int,int > stack[10000];
int find_and_print(pair <int,int> com[10000])
{
  int ok,point1,point2;
  int st[10000];
  int index[10000];
  int succesor[10000];
  int color[10000];
  int i;
  for(i=0;i<=ctop;++i)
    {
      color[com[i].first]=1;
      index[com[i].first]=i;
      if(color[com[i].second]==1)
	{
	   succesor[index[com[i].first]]=index[com[i].second];
           ok++;
	   break;
	}
    }
  int j=i+1;
  point1=index[com[j].first];
  for( i=j;i<=ctop;++i)
    {
      if(color[com[i].second]==1)
	{
	  point2=index[com[i].second];
	  ok++;
	  break;
	}
    }
  int temp;
  if(point2<point1)
    {
     temp=point2;
     point2=point1;
     point1=temp;
    }
  if(ok==2)
    { 
      cout<<"YES"<<endl;
      int piku=-1;
      cout<<i-j+2<<" ";
      for(int k=j;k<=i;++k)
        cout<<com[k].first<<" ";
      cout<<com[i].second;
      cout<<endl<<(point2-point1+1)<<" ";
      for(int k=point2;k>=point1;--k)
	cout<<com[k].first<<" ";
      while(point2!=point1)
	{
         st[++piku]=com[point2].first; 
         if(succesor[index[com[point2].first]]!=0)
	    point2=succesor[index[com[point2].first]];
          else
          point2=index[com[point2].second];
	}
      st[++piku]=com[point2].first;   
      cout<<endl<<piku+1<<" ";
      for(int i=0;i<=piku;++i)
	cout<<st[i]<<" ";
      exit(0);
    }	       
}
int dfs(int a)
{
  int child=0; 
  visited[a]=++timer;
  int min_visited=visited[a];
  vector<int>::iterator t;
  for(vector<int>::iterator c=v[a].begin();c!=v[a].end();++c)
    {
      int alex=0;
      for(t=parent[a].begin();t!=parent[a].end();++t)
	if(*t==*c)
	  {alex=1;break;} 
            
      if(alex==1)
	continue;
      else
        {
       stack[++top]=make_pair(a,*c);
       parent[*c].push_back(a);
      if(visited[*c]==0)
	{
          child++;
	  min_visited=min(min_visited,dfs(*c));
          if(min_visited>=visited[a])
	    {
	      ctop=-1;
              int temp=top;
	      while(stack[temp--].first !=a);
	      for(int k=temp+1;k<=top;++k)
		com[++ctop]=stack[k];
             find_and_print(com);
              top=temp;
            }
           if(child>1 && a==1)
            {
	      ctop=-1;
	      for(int i=0;i<=top;++i)
	        com[++ctop]=stack[i];
              find_and_print(com);
            }
	}
      else
	min_visited=min(min_visited,visited[*c]);
       }
      }
  return min_visited;
}
int main()
{
  
  int n,v1,v2,m;
  cin>>n>>m;
  fr(0,m){cin>>v1>>v2;v[v1].push_back(v2);v[v2].push_back(v1);}
  
  dfs(1);
  cout<<"NO";
 
}
