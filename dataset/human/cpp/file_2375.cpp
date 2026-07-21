#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin>>n;
  vector<long long>a(n);
  for(long long i=0;i<n;i++) cin>>a[i];
  long long ans=0;
  bool zero=false;
  long long minus=1000000000;
  long long num=0;
  for(int i=0;i<n;i++){
    ans+=abs(a[i]);
    minus=min(minus,abs(a[i]));
    if(a[i]<0) num++;
    if(a[i]==0) zero=true;
  }
  if(num%2==0 || zero) cout<<ans<<endl;
  else cout<<ans-2*minus<<endl;
}
