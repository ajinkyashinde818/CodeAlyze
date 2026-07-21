#include<bits/stdc++.h>
using namespace std;
bool custom(int a, int b){
  return abs(a) < abs(b);
}
int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; ++i) cin >> v[i];
  int cnt = 0;
  long long sum = 0;
  for(int i = 0; i < n; ++i){
    if(v[i] < 0) cnt++;
    sum += abs(v[i]);
  }
  sort(v.begin(), v.end(), custom);
  if(cnt % 2) cout << sum - abs(v[0]) * 2 << endl;
  else cout << sum << endl;
}
