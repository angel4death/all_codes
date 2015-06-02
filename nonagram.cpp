#include<iostream>
using namespace std;
int c,r,mem[6],*row,*col,found,col_count[6][21];
char get[1048576][21];
void precompute()
{
    for(int i=0;i<1048576;++i)
    {
      for(int  j=0;j<21;++j)
        {
          get[i][j]=(i/(1<<j))%2;
        }
    }
}
void calc(int idx,int mask,int row_count[])
{
  cout<<"Here";
     int rcount=0,isvalid=1;
    if(idx==r)
        return;
    for(int i=0;i<(1<<c);++i)
    {
      isvalid=1;
      rcount=0; 
        for(int j=0;j<c;++j)
	  {  
         col_count[idx][j]=0;
         if(j==0)
	   {
	     if(get[i][j]==1)
	       rcount=1;
	     else
               rcount=0;
	   }
         else
	   {
	     if(get[i][j]==1 && get[i][j-1]==0)
               rcount++;
	   }
                        
         if(get[i][j]==1)
         {
            if(get[mask][j]==1)
              col_count[idx][j]=col_count[idx-1][j];
            else
              col_count[idx][j]=col_count[idx-1][j]+1;
         }
         else
           col_count[idx][j]=col_count[idx-1][j];
         if(col_count[idx][j]>col[j] || (idx==r-1 && col_count[idx][j]!=col[j]))
           {
            isvalid=0;
            break;
           }        
                
        
        }
	/*	cout<<"index is "<<idx<<" i is "<<i<<" col values "<<col_count[idx][0]<<
		col_count[idx][1]<<col_count[idx][2]<<col_count[idx][3]<<col_count[idx][4]<<" the validiity is "<<isvalid<<" rcount" <<rcount<<endl;*/
    if(isvalid)
        {
            row_count[idx]=row_count[idx]+rcount;
            if(row_count[idx]==row[idx])
            {
             mem[idx]=i;
             if(idx==r-1)
                {
                 found=1;
                 return;
                }
            calc(idx+1,i,row_count);
            if(found==1)
                return;
             }
             row_count[idx]-=rcount;

       }
    }
}
            
int main()
{
precompute();
found=0;
cin>>r>>c;
row=new int[r]();
col=new int[c]();
for(int i=0;i<r;++i)
    cin>>row[i];
for(int i=0;i<c;++i)
    cin>>col[i];
for(int j=0;j<6;++j)
col_count[0][j]=0;
int *row_count=new int[r]();
 int isvalid=0;
for(int i=0;i<(1<<c);++i)
    {
      isvalid=1; 
    row_count[0]=0;   
    for(int j=0;j<c;++j)
        {

	  if(j==0)
	    {
	      if(get[i][j]==0)
		{
		  row_count[0]=0;
		}
	      else
		{
	         row_count[0]=1;
		}
	    }
	  else
	    {
	      if(get[i][j]==1 && get[i][j-1]==0)
		row_count[0]++;
	    }
          if(get[i][j]==1)
	    col_count[0][j]=1;
          else
            col_count[0][j]=0; 
          if(r==1)
	    {
	      if(col_count[0][j]!=col[j])
		{
                isvalid=0;
	        break;
		}
   	    }
	}
    if(row_count[0]==row[0])
      {
	mem[0]=i;
	if(r==1 && isvalid)
          break;
	 
	//	cout<<i<<" "<<col_count[0][0]<<col_count[0][1]<<col_count[0][2]<<endl;
	calc(1,i,row_count);
	 if(found==1)
          break;
      }   
   }


    
for(int i=0;i<r;++i)
{
    for(int j=0;j<c;++j)
    {
        if(get[mem[i]][j]==1)
         cout<<"*";
         else
         cout<<".";
    }
    cout<<endl;
 }
 return 0;
}


