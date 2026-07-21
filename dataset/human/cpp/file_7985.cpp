#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
  int n;cin >> n;
  ll total=0,x=0,amin=2000000001;
  vector<ll> a(n);
  for(int i=0;i<n;i++){cin >> a[i];total+=a[i];}
  for(int i=0;i<n-1;i++){
    x+=a[i];
    total-=a[i];
    amin=min(amin,abs(x-total));
  }
  cout << amin << endl;
}
