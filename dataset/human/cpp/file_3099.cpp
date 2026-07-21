#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,x=0;
  cin>>n;
  long long a[n],min=LLONG_MAX,sum=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]<0){
        a[i]*=-1;x++;
    }
    if(a[i]<min){
        min=a[i];
    }
    sum+=a[i];
  }
  if(x%2==0){cout<<sum;}
  else{cout<<sum-2*min;}
  return 0;
}
