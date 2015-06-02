#include<iostream>
using namespace std;
int main()
{
  int arr[8][9];
  int &p=arr[32][11];
  cout<<p;
}
