#include<bits/stdc++.h>
using namespace std;

int main()
{
  int64_t n,m,sum;
  m=0;
  sum=0;
  cin>>n;
  vector<int64_t> a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a.at(i);
    if(a.at(i)<0)
    {
      m++;
      a.at(i)*=-1;
    }
    sum+=a.at(i);
  }
  sort(a.begin(),a.end());
  if(m%2==0)
    cout<<sum<<endl;
  else
    cout<<sum-a.at(0)*2<<endl;
}
