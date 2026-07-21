#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0,aaa=999999999999,minus=0;
  cin >> n;
  for(long i=0;i<n;i++) {
    long a;
    cin >> a;
    if(a>0) {
      ans+=a;
      aaa=min(aaa,a);
    } else if(a<0) {
      ans+=0-a;
      aaa=min(aaa,0-a);
      if(minus<1000000000) minus++;
    } else {
      minus=1000000000;
    }
  }
  if(minus%2==1) ans-=aaa*2;
  cout << ans << endl;
}
