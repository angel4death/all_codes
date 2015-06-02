#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
static int arr[1000];
void mark(int ,int,int *);
int main()
{  
  vector<int> v;
  int len=0,num=0,index=0,value=0;
   cin>>len>>num;
  int max;
  v.push_back(1);
  for(int i=1;i<=num;++i)
    {
      cin>>index>>value;
      arr[index]=value;
      if(index!=1 && index!=len)
        v.push_back(index);
    }
  v.push_back(len);
  vector<int>::iterator k=v.end();
   for(vector<int>::iterator i=v.begin();i!=k;++i)
    {
     mark(*i,*(i+1),arr);
    }
  int mx=0,found=0;
  for(int j=1;j<=len;++j)
    {

      cout<<arr[j]<<" ";
      /*
      if(arr[j+1]-arr[j]<=1 && arr[j+1]-arr[j]>=-1)
	{
	  int c=(arr[j]>arr[j+1])?arr[j]:arr[j+1];
          if(c>mx)
	    mx=c;
	}
      else
	{
        found=1;
	break;	  
	}
*/
    }
  /*
  if(found==1)
    cout<<"IMPOSSIBLE";
  else 
    cout<<mx;
  */
 return 0;
}


void mark(int low,int high,int *arr)
{
  int mid=0;
  mid=(high+low)/2;
  if(low==(high-1))
    return ;
  if(arr[low]<=arr[high])
    {

      if((arr[low]+(mid-low))>(arr[high]-(high-mid)))
        {
	  arr[mid]=arr[low]+(mid-low);
          mark(mid,high,arr);
          mark(low,mid,arr);
	}
      else if(arr[low]+(mid-low)==arr[high]-(high-mid))
        {
	    arr[mid]=arr[low]+(mid-low);
            return;
	}
      else
	{
	  arr[mid]=-10;
          return; 
	}
    }
  else
    {
      
      if((arr[low]-(mid-low))<(arr[high]+(high-mid)))
        {
          arr[mid]=arr[low]-(mid-low);
          mark(low,mid,arr);
          mark(mid,high,arr);
	}
      else if(arr[low]-(mid-low)==arr[high]+(high-mid))
        {
	    arr[mid]=arr[high]+(mid-low);
            return;
	}
      else
	{
	  arr[mid]=-10;
          return; 
	}
    }
} 
   
 
