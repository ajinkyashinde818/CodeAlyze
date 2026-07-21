#include<bits/stdc++.h>
using namespace std;
int rating(int n,int r)
{
  if(n>10)
    return r;
  else
  {
    r=r+100*(10-n);
    return r;
  }
}
int main()
{
  int n,r,res;
  cin>>n>>r;
  res=rating(n,r);
  cout<<res<<endl;
  return 0;
}
