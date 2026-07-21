#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int c;
typedef long long ll;
ll a[100005];
int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    ll A;
    cin >> A;
    if(A < 0ll) c++;
    a[i] = abs(A);
  }
  sort(a,a+n);
  ll s = 0;
  if(c % 2) {
    for(int i = 0; i < n; i++) s += a[i];
    cout << s - a[0] * 2 << endl;
  }
  else {
    for(int i = 0; i < n; i++) s += a[i];
    cout << s << endl;
  }
}
