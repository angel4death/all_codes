#include<iostream>
#include<cstring>
using namespace std;
int main()
{
  int *m[10][10];
  int *p;
  memset(p,0,5*sizeof(int));
  m[4][5]=p;
  for(int i=0;i<5;++i)
    cout<<m[4][5][i];

}
