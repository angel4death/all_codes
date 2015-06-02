#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
long long weights[4000001],n,length;
long long find_path(vector<pair<long long,long long> > , long long);
int main()
{
  pair<long long,long long> my_pair;
  vector<pair<long long,long long> >  v; 
  cin>>n;
  for(long long i=1;i<=n;++i)
    cin>>weights[i];
  cin>>length;
  vector<pair<long long,long long> >::iterator i;
  for(long long j=1;j<=length;++j)
    {
      cin>> my_pair.first;
      if(v.empty())
        {
      
          my_pair.second=1;
          v.push_back(my_pair);
    }
      else
    {
      i=v.end();
      i--;
     if(i->first==my_pair.first)
       i->second++;
     else
       {
         my_pair.second=1;
         v.push_back(my_pair);
       }
    }
    }
  long long pos=0,dis=0,l=-1,p_length=-1;
  for(i=v.begin();i!=v.end();++i)
    {
      l=find_path(v,pos);
      if(l!=-1)
      {
      if(dis==1)
          {
        if(l!=p_length)
          {
            cout<<-1;
            return 0;
          }
          }
        else if(dis==0)
          {
        dis=1;
        p_length=l;
          }
       }   
       pos++;
    }
  cout<<p_length;
}

long long find_path(vector<pair<long long,long long> > p,long long start)
{
  long long count=1,l=0;
  long long path_arr[400001];
  vector<pair<long long,long long> >:: iterator v;
  v=p.begin()+start;
  path_arr[count++]=v->first;
  v->second-=1;
  v++;   
  while(count<=length)
    {
      if(v!=p.end())
    {
      if(v->second > 0 && v->first !=0)
    {
      path_arr[count++]=v->first;
      l+=abs(weights[path_arr[count-1]]-weights[path_arr[count-2]]);
      v->second-=1; 
      v++;
    }
      else
    {
      return -1;
    }
    }
      else if(v==p.end())
    {
      reverse(p.begin(),p.end());
      v=p.begin()+1;
    }
    }
  return l;
}
