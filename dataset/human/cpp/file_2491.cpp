#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x = 0;
  long long sum = 0LL;
  cin >> n;
  vector<long long> a(n);
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
    if(a.at(i) < 0){
      a.at(i) *= -1LL;
      x++;
    }
    sum += a.at(i);
  }
  if(x % 2 == 1){
    sort(a.begin(), a.end());
    sum -= a.at(0) * 2LL;
  }
  cout << sum << endl;
}
