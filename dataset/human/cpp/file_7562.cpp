#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  long long sum=0;
  vector<int > a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(i==n-1) break;
    sum+=a[i];
  }
  long long ans=100000000000000,s2=a[n-1];
  for(int i=n-2;i>=0;i--){
    ans=min(ans,abs(sum-s2));
    sum-=a[i];
    s2+=a[i];
  }
  cout<<ans<<endl;
}
