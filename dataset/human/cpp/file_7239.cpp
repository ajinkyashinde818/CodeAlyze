#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int N;
  cin >> N;
  ll a[N],x=0,z=LLONG_MAX,y=0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    x+=a[i];
  }
  for (int i = 0; i < N-1; i++) {
    y += a[i];
    x -= a[i];
    z = min(z,abs(x-y));
  }
  cout<<z;
}
