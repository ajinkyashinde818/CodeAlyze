#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{ 
  int i,j,k,a[200000],b[200000],n;
  int c;
  cin>>n;
  
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }
  
  for(i=0;i<n;i++)
  {
    cin>>b[n-i-1];
  }
  j=0,k=n-1;
  
  for(i=0;i<n;i++)
  {
    if(a[i]==b[i])
    {
      c=b[i];
      b[i]=b[j];
      b[j]=c;
      
      if(b[i]==a[i]||a[j]==b[j])
      { 
        c=b[i];
        b[i]=b[j];
        b[j]=c;
        c=b[i];
        b[i]=b[k];
        b[k]=c;
        k--;
        if(a[i]==b[i])
        {
          cout<<"No"<<endl;
          return 0;
        }
        j--;
      }
      j++;
    }
    
  
  }
  cout<<"Yes"<<endl;
  for(i=0;i<n;i++)
  {
  cout<<b[i]<<" ";
  }
  cout<<endl;
  
  
  /*
  amax=0,bmax=0;
  cmax=1;
  for(i=1;i<n;i++)
  {
    if(a[i]==a[i-1]){cmax++;}
    else
    {
      if(cmax>amax){amax=cmax;anum=a[i-1];}
      cmax=1;
    }
    if(i==n-1)
    { 
      
      if(cmax>amax)
      {
        amax=cmax;
        anum=a[i];
      }
    }
  }
  
   for(i=1;i<n;i++)
  {
    if(b[i]==b[i-1]){cmax++;}
    else
    {
      if(cmax>bmax){bmax=cmax;bnum=a[i-1];}
      cmax=1;
    }
    if(i==n-1)
    { 
      
      if(cmax>bmax)
      {
        bmax=cmax;
        bnum=b[i];
      }
    }
  }
  
  
  cout<<"amax="<<amax<<",anum="<<anum<<endl;
  cout<<"bmax="<<bmax<<",bnum="<<bnum<<endl;
  */
  
}
