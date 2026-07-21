#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,count;
  cin>>n;
  count=0;
  long long a[n];
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    a[i]=abs(k);
    if(k<0)count++;
  }
  sort(a,a+n);
  long long ans;
  if(count%2==0)ans=a[0];
  else ans=a[0]*(-1);
  for(int i=1;i<n;i++){
    ans+=a[i];
  }
  cout<<ans<<endl;
}
