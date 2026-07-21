#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

void solve(){
  int n, cnt = 0; cin >> n;
  long long x = 1000000000, sum = 0;
  vector<long long> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(a[i] < 0) cnt++;
    sum += abs(a[i]);
    x = min(x, abs(a[i]));
  }
  if(cnt % 2 == 0){
    cout << sum << endl;
  }
  else{
    cout << sum - x * 2 << endl;
  }

  return;
}

int main(){
  solve();
  return 0;
}
