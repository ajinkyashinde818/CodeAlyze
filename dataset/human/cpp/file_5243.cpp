#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
  int n,r;
  
  cin>>n>>r;
  
  if(n<=10)
  {
    r=r+100*(10-n);
    cout<<r<<endl;
  }
  else
  {
    cout<<r<<endl;
  }

  return 0;
}
