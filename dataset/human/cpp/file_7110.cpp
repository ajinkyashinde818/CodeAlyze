#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main(){
  int n; cin >> n;
  ll a[n];
  ll s=0;
  for(int i=0; i<n; i++) {
    cin >> a[i];
    s += a[i];
  }

  ll snuke=0, arai;
  ll ans = 1e11;
  for(int i=0; i<n-1; i++){
    snuke += a[i];
    ans = min(ans, abs(snuke-(s-snuke)));
  }

  cout << ans << endl;

  return 0;
}
