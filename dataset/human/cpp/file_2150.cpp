#include<bits/stdc++.h>
using namespace std;
int main()
{
long long n;
cin>>n;
vector<long long> a(n);
long long neg=0;
  for(int i=0;i<n;i++)
  {
  	cin>>a[i];
  	  if(a[i]<0)
  	    neg++,
  	    a[i]*=-1;
  }
sort(a.begin(),a.end());
long long sum=0;
  for(int i=0;i<n;i++)
    sum+=a[i];
neg%=2;
  if(neg)
    sum-=a[0]*2;
cout<<sum<<endl;
return 0;
}
