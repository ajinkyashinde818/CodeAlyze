#include<bits/stdc++.h>
using namespace std;
int myabs(int a)
{
  if(a>0) return a;
  else return -a;
}
int main()
{
  int n,mi=2147483647;
  long long sum=0;
  cin>>n;
  bool flag=false;
  for(int i=0;i<n;i++)
  {
    int b;
    cin>>b;
    sum+=myabs(b);
    if(b<0) flag=1-flag;
    if(myabs(b)<mi) mi=myabs(b);
  }
  if(flag) cout<<sum-2*mi<<'\n';
  else cout<<sum<<'\n';
  return 0;
}
