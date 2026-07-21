#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  int n;
  cin>>n;

  ll a[100005];
  bool zero=false;
  for (int i=0; i<n; i++) {
    cin>>a[i];
    if (a[i]==0) {
      zero=true;
    }
  }
  ll sum=0;
  if (zero) {
    for (int i=0; i<n; i++) {
      sum+=abs(a[i]);
    }
  }
  else {
    for (int i=0; i<n; i++) {
      sum+=abs(a[i]);
    }
    int cnt_m=0;
    for (int i=0; i<n; i++) {
      if (a[i]<0) cnt_m++;
    }
    if (cnt_m%2==1) {
      ll e=1e18;
      for (int i=0; i<n; i++) {
	e=min(e,abs(a[i]));
      }
      sum-=e*2;
    } 
  }
  
  cout<<sum<<endl;
  return 0;
}
