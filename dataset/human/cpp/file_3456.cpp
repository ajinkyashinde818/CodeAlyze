#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n; cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; ++i) cin >> v[i];
  for(int i = 0; i + 1 < n; ++i) {
    if(v[i] < 0) {
      v[i] = -v[i];
      v[i + 1] = -v[i + 1];
    }
  }

  long long sum = 0;
  bool was = false;
  int best = 2e9;
  for(int i = 0; i < n; ++i) {
    if(v[i] < 0) was = true;
    best = min(best, abs(v[i]));
    sum += abs(v[i]);
  }
  
  if(was) sum -= (best << 1);
  cout << sum << endl;
}
